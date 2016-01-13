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
    Nothing=0,
    MouseLeftPressed
};

class GraphicsScene:public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene(QGraphicsScene*parent=0);
    ~GraphicsScene();

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
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private slots:
    void slotSelectionChanged();
private:
    void createUI();
    void createConnect();
private:
    int oper;
    QGraphicsItem *currentItem;
//    QGraphicsScene *scene;
    GraphicsScene *scene;
};

#endif // CENTRALWIDGET_H
