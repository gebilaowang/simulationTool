#include "mainwindow.h"
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include "warningwidget.h"
#include "centralwidget.h"
#include "controllistwidget.h"
#include "controlfactory.h"

#define MAINWINDOW_ENBALE 1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if MAINWINDOW_ENBALE
    MainWindow w;
    w.show();

    //    ControlListWidget w;
    //    w.show();

    //    WarningWidget w;
    //    IssueWidget w;
    //    w.show();

    //    CentralWidget w;
    //    w.show();

    QDesktopWidget *desktop=QApplication::desktop();
    w.resize(desktop->width()*3/4,desktop->height()*3/4);
    w.move((desktop->width()-w.width())/2,
           (desktop->height()-w.height())/2);
#else
    ControlFactory f;

    QGraphicsView* view =new QGraphicsView;
    QGraphicsScene* scene=new QGraphicsScene;
    view->setScene(scene);

    ControlGraphicsProxyWidget *circle=f.getProduct("Circle");
//    scene->addWidget(circle);
    scene->addItem(circle);

    QWidget *widget=new QWidget;
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(view);
    widget->resize(400,400);
    widget ->setLayout(layout);
    widget ->show();
#endif

    return a.exec();
}
