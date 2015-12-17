#include <QDockWidget>
#include <QDateTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QLabel>
#include <QStyle>
#include <QDebug>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QTextEdit>

#include "centralwidget.h"
#include "propertytreewidget.h"
#include "warningwidget.h"
#include "controllistwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //    setStyleSheet("background-color:green");
    createUI();
    createParam();
    createConnects();

    //    createToolBar();

    //    QAction *fileAction=new QAction("&File",this);
    //    QAction *openAction=new QAction("&Open",this);

    //    QMenuBar *fileMenu=menuBar();
    //    fileMenu->addAction(fileAction);
    //    fileMenu->addAction(openAction);

}

MainWindow::~MainWindow()
{
    
}

void MainWindow::slotOpenFile()
{

}

void MainWindow::slotStatusTime()
{
    statusTimeLabel->setText(QDateTime::currentDateTime().toString(Qt::ISODate));
}

void MainWindow::createUI()
{
    createMenuBar();
    createStatusBar();

    centralWidget=new CentralWidget;
    setCentralWidget(centralWidget);

    propertyTreeWidget=new PropertyTreeWidget;
    controlListWidget=new ControlListWidget;
    warningWidget=new WarningWidget;

    addDockWidget(Qt::LeftDockWidgetArea,controlListWidget);
    addDockWidget(Qt::RightDockWidgetArea,propertyTreeWidget);
    addDockWidget(Qt::BottomDockWidgetArea,warningWidget);
}

void MainWindow::createMenuBar()
{
    //  QStyle::SP_TitleBarMenuButton QStyle::SP_TitleBarMinButton
    //    QStyle style;

    //    QIcon icon;
    //    icon=style.standardIcon(QStyle::SP_TitleBarMenuButton);
    QAction *openAction=new QAction("&Open",this);

    QMenu *fileMenu=menuBar()->addMenu("&File");
    fileMenu->addAction(openAction);
}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

void MainWindow::createStatusBar()
{
    statusLabel=new QLabel("All Ready.");
    statusTimeLabel=new QLabel("statusTimeLabel");

    QWidget *statusWidget=new QWidget;
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(statusLabel);
    //    layout->addStretch(1000);
    layout->addWidget(statusTimeLabel,0,Qt::AlignRight);

    statusWidget->setLayout(layout);

    statusBar()->addWidget(statusWidget,1);
}

void MainWindow::createParam()
{
    timer=new QTimer;
    timer->start(1000);
}

void MainWindow::createConnects()
{
    connect(timer,SIGNAL(timeout()),
            this,SLOT(slotStatusTime()));
}
