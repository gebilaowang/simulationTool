#include <QTextEdit>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>

#include "centralwidget.h"
#include "rectangle.h"
#include "controlfactory.h"

GraphicsScene::GraphicsScene(QGraphicsScene *parent)
    :QGraphicsScene(parent),
      currentItem(NULL),
      oper(Nothing)
{

}

GraphicsScene::~GraphicsScene()
{

}

GraphicsView::GraphicsView()
    :oper(Nothing),currentItem(NULL)
{
    createUI();
    //    createConnect();
    connect(scene,SIGNAL(selectionChanged()),
            this,SLOT(slotSelectionChanged()));
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void GraphicsView::dropEvent(QDropEvent *event)
{
    QString dataStr=event->mimeData()->text();
    qDebug()<<"void CentralWidget::dropEvent(QDropEvent *e)--"<<dataStr;

    ControlFactory *factory=new ControlFactory;
    ControlGraphicsProxyWidget *control=factory->getProduct("Circle");
    if(control==NULL)
    {
        qDebug()<<"void GraphicsView::dropEvent(QDropEvent *event)--"
               <<"control is NULL--";
        return;
    }
    control->setToolTip("Circle");
    control->setPos(mapToScene(event->pos()));

    //    qDebug()<<event->pos()<<mapToScene(event->pos());
    scene->addItem(control);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        currentItem=scene->itemAt(mapToScene(event->pos()));
        if(currentItem)
        {
            setDragMode(QGraphicsView::NoDrag);

            currentItem->setFlag(QGraphicsItem::ItemIsSelectable);
            currentItem->setSelected(true);

            slotSelectionChanged();

            qDebug()<<"currentItem"<<currentItem->toolTip()<<currentItem->isSelected();

        }
        else
            setDragMode(QGraphicsView::RubberBandDrag);

        oper=MouseLeftPressed;
        event->accept();
    }
    else
        QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
#if 1
    if(oper==MouseLeftPressed)
    {
        if(currentItem!=NULL)
        {
            //        qDebug()<<currentItem->pos()<<event->pos();
            currentItem->setPos(mapToScene(event->pos()));
        }
        //        return;
    }
    event->accept();
#endif
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    oper=Nothing;
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::slotSelectionChanged()
{
    qDebug()<<"void GraphicsView::slotSelectionChanged()--"
           <<    scene->selectedItems().size();

    if(scene->selectedItems().size()==1)
    {
        QGraphicsItem *item=scene->selectedItems().first();
        if(item==NULL)
            return;

        QGraphicsProxyWidget *proxyWidget=static_cast<QGraphicsProxyWidget*>(item);
        if(proxyWidget==NULL)
            return;
        QWidget *controlWidget=proxyWidget->widget();
        if(controlWidget==NULL)
            return;

        qDebug()<<"widget"<<controlWidget->metaObject()->className();

    }
}

void GraphicsView::createUI()
{
    //    setDragMode(QGraphicsView::RubberBandDrag);
    resize(800,800);
    setAcceptDrops(true);
    //        setStyleSheet("background-color:green");
    scene=new GraphicsScene;
    scene->setBackgroundBrush(QBrush(Qt::lightGray));
    scene->setSceneRect(QRectF(0,0,width(),height()));
    setScene(scene);
}

void GraphicsView::createConnect()
{
    connect(scene,SIGNAL(selectionChanged()),
            this,SLOT(slotSelectionChanged()));
}
