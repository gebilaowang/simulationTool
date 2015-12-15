#include "mainwindow.h"
#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    setStyleSheet("background-color:green");
    createUI();
    createMenuBar();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::createUI()
{
    menuBar();


    centralWidget=new CentralWidget;
    centralWidget->setParent(this);

//    setCentralWidget(centralWidget);

    QTextEdit *textEdit=new QTextEdit;
    setCentralWidget(textEdit);
}

void MainWindow::createMenuBar()
{
       openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
       openAction->setShortcuts(QKeySequence::Open);
       openAction->setStatusTip(tr("Open an existing file"));

       QMenu *file = menuBar()->addMenu(tr("&File"));
       file->addAction(openAction);

}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}


CentralWidget::CentralWidget()
{
//    setAutoFillBackground(true);
    setStyleSheet("background-color:green");
}

CentralWidget::~CentralWidget()
{

}
