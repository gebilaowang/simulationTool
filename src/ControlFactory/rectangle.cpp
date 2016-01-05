#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(ControlBaseWidget *parent) :
    ControlBaseWidget(parent)
{
}

void Rectangle::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect rect(0,0,100,100);
    painter.setPen(QPen(Qt::red));
    painter.drawRect(rect);

    painter.end();
    QWidget::paintEvent(e);
}
