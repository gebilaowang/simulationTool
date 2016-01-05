#include "circle.h"
#include <QPainter>

Circle::Circle(ControlBaseWidget *parent):
    ControlBaseWidget(parent)
{
}

Circle::~Circle()
{

}

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //    QRect rect(0,0,100,100);
    //   painter->setPen(QPen(Qt::green));
    //    painter->drawRect(rect);

    painter.setPen(QPen(Qt::blue,4,Qt::SolidLine));
    painter.drawEllipse(20,20,210,160);
    painter.end();

    QWidget::paintEvent(e);
}
