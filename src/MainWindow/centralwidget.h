#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

class QGraphicsView;
class QSplitter;
class QGraphicsScene;
class QDragEnterEvent;
class QDropEvent;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
private:
    void createUI();
    void setSplitterSize();
private:
    QGraphicsView *view;
    QGraphicsScene *scene;

    QSplitter *splitter;
    QWidget *warningWidget;
};

#endif // CENTRALWIDGET_H
