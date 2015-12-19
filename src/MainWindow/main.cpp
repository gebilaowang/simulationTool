#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include "warningwidget.h"
#include "centralwidget.h"
#include "controllistwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
    
    return a.exec();
}
