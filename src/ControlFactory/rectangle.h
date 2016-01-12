#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include "controlbasewidget.h"

class Rectangle : public ControlBaseWidget
{
    Q_OBJECT
public:
    explicit Rectangle(ControlBaseWidget *parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
    
public slots:
    
};

#endif // RECTANGLE_H
