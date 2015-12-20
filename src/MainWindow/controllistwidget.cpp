#include "controllistwidget.h"
#include <QDragMoveEvent>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <QModelIndex>
#include <QTreeWidget>
#include <QHBoxLayout>

ControlListWidget::ControlListWidget(QWidget *parent) :
    QWidget(parent)
{
    createUI();
    createConnects();
}

ControlListWidget::~ControlListWidget()
{

}

void ControlListWidget::createUI()
{
    setWindowTitle("ContorList");

    tree=new QTreeWidget;
    tree->setColumnCount(1);
    for(int i=0;i<10;i++)
    {
        QTreeWidgetItem *item=new QTreeWidgetItem;
        item->setText(0,QString::number(i));

        tree->addTopLevelItem(item);
    }

    QHBoxLayout *layout=new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(tree);

    setLayout(layout);
}

void ControlListWidget::createConnects()
{
    //    connect(tree,SIGNAL(pressed(QModelIndex)),this,SLOT(slotStartDarg(QModelIndex)));
    connect(tree,SIGNAL(itemPressed(QTreeWidgetItem*,int)),this,SLOT(slotStartDarg()));
}

void ControlListWidget::slotStartDarg()
{
    QTreeWidgetItem *item=tree->currentItem();
    if(item==0)
        return;
    qDebug()<<"void ControlListWidget::slotStartDarg()--"
           <<item->text(0);

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    mimeData->setText(item->text(0));
    drag->setMimeData(mimeData);
    drag->exec();
}

