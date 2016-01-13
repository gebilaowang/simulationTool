#include <QDockWidget>
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

void PropertyTreeWidget::slotGetControlWidget(QWidget *)
{

}

void PropertyTreeWidget::createUI()
{
    treeWidget=new QTreeWidget;
    treeWidget->setHeaderHidden(true);
    QTreeWidget *tree2=new QTreeWidget;

    QVBoxLayout *layout=new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(treeWidget);
//    layout->addWidget(tree2);

    setLayout(layout);
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

    ControlGraphicsProxyWidget *circle=f.getProduct("Circle");
//    scene->addWidget(circle);
    scene->addItem(circle);

    PropertyTreeWidget *treeWidget=new PropertyTreeWidget;
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(view);
    layout->addWidget(treeWidget);

    setLayout(layout);
}
