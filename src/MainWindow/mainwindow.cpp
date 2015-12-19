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
    setWindowTitle("SimulationTool");
    //    setStyleSheet("background-color:green");
    createUI();
    createParam();
    createConnects();

    //    createToolBar();

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

    leftDockWidget=new QDockWidget(this);
    rightDockWidget=new QDockWidget;
    bottomDockWidget =new QDockWidget;

    propertyTreeWidget=new PropertyTreeWidget;
    controlListWidget=new ControlListWidget;
    warningWidget=new WarningWidget;

    leftDockWidget->setWidget(controlListWidget);
    rightDockWidget->setWidget(propertyTreeWidget);
    bottomDockWidget->setWidget(warningWidget);

    leftDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    rightDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    bottomDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);

    leftDockWidget->setWindowTitle("ControlList");

    addDockWidget(Qt::LeftDockWidgetArea,leftDockWidget);
    addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);
//    centralWidget->addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);

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
