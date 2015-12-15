#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CentralWidget;
class QAction;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createUI();
    void createMenuBar();
    void createToolBar();
private:
    CentralWidget *centralWidget;
QAction *openAction;
};

class CentralWidget:public QWidget
{
        Q_OBJECT
public:
    CentralWidget();
    ~CentralWidget();
};

#endif // MAINWINDOW_H
