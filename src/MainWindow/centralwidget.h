#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

class QGraphicsView;
class QSplitter;
class QDragEnterEvent;
class QDropEvent;

class GraphicsScene;
class GraphicsView;

enum Operation
{
    MouseLeftPressed=0
};

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
private:
    void createUI();
    void createConnect();
    void setSplitterSize();
private:
    QGraphicsView *view;
    QGraphicsScene *scene;

//    GraphicsView *view;
//    GraphicsScene *scene;

    QSplitter *splitter;
    QWidget *warningWidget;
};

class GraphicsScene:public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene(QGraphicsScene*parent=0);
    ~GraphicsScene();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    short oper;
    QGraphicsItem *currentItem;
};

class GraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();
    ~GraphicsView();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // CENTRALWIDGET_H
