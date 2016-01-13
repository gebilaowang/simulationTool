#include "mainwindow.h"
#include <QTextCodec>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include "warningwidget.h"
#include "centralwidget.h"
#include "controllistwidget.h"
#include "controlfactory.h"
#include "propertytreewidget.h"

#define MAINWINDOW_ENBALE 0

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    if(codec)
    {
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForTr(codec);
    }

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
    PropertyTestWidget *w=new PropertyTestWidget;
    w->show();

    QDesktopWidget *desktop=QApplication::desktop();
    w->resize(desktop->width()*3/4,desktop->height()*3/4);
    w->move((desktop->width()-w->width())/2,
           (desktop->height()-w->height())/2);
#endif


    return a.exec();
}
