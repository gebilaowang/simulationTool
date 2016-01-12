#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include "controlbasewidget.h"
#include "controlgraphicsproxywidget.h"

class CircleWidget;
class Circle : public ControlGraphicsProxyWidget
{
    Q_OBJECT
public:
    explicit Circle(ControlGraphicsProxyWidget *parent=0);
    ~Circle();

//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class CircleWidget:public QWidget
{
    Q_OBJECT
public:
    CircleWidget();
    ~CircleWidget();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // CIRCLE_H
