#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "centralwidget.h"

class CentralWidget;
class QLabel;
class PropertyTreeWidget;
class ControlListWidget;
class WarningWidget;
class CentralWidget;
class QAction;
class GraphicsView;

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
    void createStatusBar();
    void createParam();
    void createConnects();
private slots:
    void slotOpenFile();
    void slotStatusTime();
private:
    QTimer *timer;
private:
    QAction *openAction;
    QDockWidget *leftDockWidget,*rightDockWidget,*bottomDockWidget;
    QLabel *statusLabel,*statusTimeLabel;

    CentralWidget *centralWidget;
    GraphicsView *view;
    PropertyTreeWidget *propertyTreeWidget;
    ControlListWidget *controlListWidget;
    WarningWidget *warningWidget;
};

#endif // MAINWINDOW_H
