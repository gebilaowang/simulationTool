#include <QDockWidget>
#include <QStandardItemModel>
#include <QTreeView>
#include <QHeaderView>
#include <QDebug>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "controlfactory.h"
#include "propertytreewidget.h"

PropertyTreeWidget::PropertyTreeWidget(QWidget *parent) :
    QWidget(parent)
{
    createUI();
}

void PropertyTreeWidget::slotGetControlTarget(QWidget *w)
{
    qDebug()<<w->metaObject()->className();
    ControlBaseWidget *control=static_cast<ControlBaseWidget*>(w);
    proVariantMap=control->getProVariantMap();

    foreach(QString name,proVariantMap.keys())
    {
        QVariant v=control->property(name.toLatin1().data());
        if(v.isValid())
        {
            PropertyInfo info=(PropertyInfo)proVariantMap.value(name);
            info.variant=v;
            proVariantMap.insert(info.name,info);
        }
    }

    createCommonModel();
}

void PropertyTreeWidget::createUI()
{
    commonTree=new QTreeWidget;
    QStringList headerList;
    headerList.append("Property");
    headerList.append("Value");
    commonTree->setHeaderLabels(headerList);

    commonTreeView=new QTreeView;

    QVBoxLayout *layout=new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(commonTreeView);

    setLayout(layout);
}


void PropertyTreeWidget::createPropertyTree()
{
    commonTree->setColumnCount(2);
    //    commonTree->addTopLevelItem(new QTreeWidgetItem(QStringList("普通属性")));
    QTreeWidgetItem *commonTreeItem=new QTreeWidgetItem(QStringList("普通属性"));
    commonTree->addTopLevelItem(commonTreeItem);

    //    commonTreeItem->addChild();
}

void PropertyTreeWidget::createCommonModel()
{
    commonModel=new QStandardItemModel;
    commonModel->setColumnCount(2);

    QStringList headerList;
    headerList.append("Property");
    headerList.append("Value");
    commonModel->setHorizontalHeaderLabels(headerList);

    QMap<QString,PropertyInfo>::const_iterator iterator=proVariantMap.constBegin();
    while(iterator!=proVariantMap.constEnd())
    {
        PropertyInfo info=(PropertyInfo)iterator.value();

        QStandardItem *proItem=new QStandardItem;
        proItem->setText(info.chName);
        proItem->setEditable(false);

        QStandardItem *valueItem=new QStandardItem;
        valueItem->setText(info.variant.toString());

        QList<QStandardItem*> itemList;
        itemList.append(proItem);
        itemList.append(valueItem);

        commonModel->appendRow(itemList);

        //        qDebug()<<"info"<<info.name<<info.chName<<info.variant;

        iterator++;
    }


    commonTreeView->setModel(commonModel);

}

PropertyTestWidget::PropertyTestWidget()
{
    createUI();
}

void PropertyTestWidget::createUI()
{
    setWindowTitle("PropertyTestWidget");

    ControlFactory f;

    QGraphicsView* view =new QGraphicsView;
    QGraphicsScene* scene=new QGraphicsScene;
    view->setScene(scene);

    ControlBaseWidget *circle=f.getProduct("Circle");
    //    scene->addItem(circle);
    scene->addWidget(circle);

    PropertyTreeWidget *proWidget=new PropertyTreeWidget;
    connect(this,SIGNAL(sigControlTarget(QWidget*)),
            proWidget,SLOT(slotGetControlTarget(QWidget*)));

    emit sigControlTarget(circle);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(view);
    layout->addWidget(proWidget);

    setLayout(layout);
}
