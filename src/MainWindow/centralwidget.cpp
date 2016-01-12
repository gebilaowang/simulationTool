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

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    setAcceptDrops(true);
    setMouseTracking(true);
    createUI();
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::dragEnterEvent(QDragEnterEvent *e)
{
    e->acceptProposedAction();
}

void CentralWidget::dropEvent(QDropEvent *e)
{
    QString dataStr=e->mimeData()->text();
    qDebug()<<"void CentralWidget::dropEvent(QDropEvent *e)--"<<dataStr;

    ControlFactory *factory=new ControlFactory;
    ControlGraphicsProxyWidget *control=factory->getProduct("Circle");
    control->setToolTip("Circle");
    control->setPos(view->mapToScene(e->pos()));

    qDebug()<<e->pos()<<view->mapToScene(e->pos());

    scene->addItem(control);
}

void CentralWidget::createUI()
{
    view =new GraphicsView;
    view->setAcceptDrops(false);
    view->setMouseTracking(true);
    scene=new GraphicsScene;
    scene->setSceneRect(QRectF(0, 0, 800,800));
    view->setScene(scene);

    warningWidget=new QWidget;
    warningWidget->setStyleSheet("background-color:green");

    splitter=new QSplitter(Qt::Vertical);
    splitter->addWidget(view);
    //    splitter->addWidget(warningWidget);

    QVBoxLayout *layout=new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(splitter);
    //    layout->addWidget(view);

    setLayout(layout);

    setSplitterSize();
}

void CentralWidget::createConnect()
{
}

void CentralWidget::setSplitterSize()
{
    QList<int> sizeList;
    sizeList.append(height()*4/5);
    sizeList.append(height()/5);

    splitter->setSizes(sizeList);
}


GraphicsScene::GraphicsScene(QGraphicsScene *parent)
    :QGraphicsScene(parent),
      currentItem(NULL),
      oper(-1)
{

}

GraphicsScene::~GraphicsScene()
{

}

void GraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"graphicsScene dragEnterEvent--";
    event->setAccepted(true);
}

void GraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QString dataStr=event->mimeData()->text();
    qDebug()<<"void CentralWidget::dropEvent(QDropEvent *e)--"<<dataStr;

    ControlFactory *factory=new ControlFactory;
    ControlGraphicsProxyWidget *control=factory->getProduct("Circle");
    control->setToolTip("Circle");
    control->setPos(event->scenePos());
    addItem(control);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"GraphicsScene mousePressEvnet button--"
           <<event->type()
          <<event->button();

    if(event->button()!=Qt::LeftButton)
        return;
#if 0
    oper=MouseLeftPressed;

    currentItem=itemAt(event->scenePos());
    if(currentItem==NULL)
    {
        return;
    }
    qDebug()<<"Scene mousepressEvnet--"<<currentItem->toolTip();
#endif
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(oper!=MouseLeftPressed)
        return;

    qDebug()<<"mouseMoveEvnet--"<<event->scenePos();

    if(currentItem==NULL)
        return;

    currentItem->setPos(event->pos());;vb

    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //    qDebug()<<"GraphicsScene mouseReleaseEvent--";
    oper=-1;

    QGraphicsScene::mouseReleaseEvent(event);
}


GraphicsView::GraphicsView()
{

}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void GraphicsView::dropEvent(QDropEvent *event)
{

}
