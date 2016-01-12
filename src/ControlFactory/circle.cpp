#include "circle.h"
#include <QPainter>

Circle::Circle(ControlGraphicsProxyWidget *parent):
    ControlGraphicsProxyWidget(parent)
{
    resize(100,100);
    CircleWidget *circleWidget=new CircleWidget;
    setWidget(circleWidget);
}

Circle::~Circle()
{

}
#if 0
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue,4,Qt::SolidLine));
    painter->drawEllipse(0,0,80,80);
    painter->end();
}
#endif

CircleWidget::CircleWidget()
{
    resize(100,100);
}

CircleWidget::~CircleWidget()
{

}

void CircleWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //    QRect rect(0,0,100,100);
    //   painter->setPen(QPen(Qt::green));
    //    painter->drawRect(rect);

    painter.setPen(QPen(Qt::blue,4,Qt::SolidLine));
    painter.drawEllipse(0,0,80,80);
    painter.end();

    QWidget::paintEvent(e);
}
