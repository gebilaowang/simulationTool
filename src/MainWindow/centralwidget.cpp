#include <QTextEdit>
#include <QDebug>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>

#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    setAcceptDrops(true);
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
}

void CentralWidget::createUI()
{
    scene=new QGraphicsScene(this);
    view =new QGraphicsView(this);

    view->setScene(scene);

    warningWidget=new QWidget;
    warningWidget->setStyleSheet("background-color:green");

    splitter=new QSplitter(Qt::Vertical);
    splitter->addWidget(view);
    splitter->addWidget(warningWidget);


    //    QHBoxLayout *layout=new QHBoxLayout;
    QVBoxLayout *layout=new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(splitter);
    //    layout->setMargin(1);
    //    layout->addWidget(view);

    setLayout(layout);

    setSplitterSize();
}

void CentralWidget::setSplitterSize()
{
    QList<int> sizeList;
    sizeList.append(height()*4/5);
    sizeList.append(height()/5);

    splitter->setSizes(sizeList);
}

