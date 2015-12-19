#include "controllistwidget.h"
#include <QTreeWidget>
#include <QHBoxLayout>

ControlListWidget::ControlListWidget(QWidget *parent) :
    QWidget(parent)
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
