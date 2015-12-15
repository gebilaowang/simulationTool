#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    CentralWidget w;
//    w.show();
    MainWindow w;
    w.show();

    QDesktopWidget *desktop=QApplication::desktop();
    w.resize(desktop->width()*3/4,desktop->height()*3/4);
    w.move((desktop->width()-w.width())/2,
           (desktop->height()-w.height())/2);
    
    return a.exec();
}
