#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(ControlBaseWidget *parent) :
    ControlBaseWidget(parent)
{
    resize(100,100);
}


#if 0
void Rectangle::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect rect(0,0,99,99);
    painter.setPen(QPen(Qt::red));
    painter.drawRect(rect);

    painter.end();
    QWidget::paintEvent(e);
}
#endif
