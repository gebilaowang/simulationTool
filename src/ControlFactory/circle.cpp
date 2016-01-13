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

CircleWidget::CircleWidget():
    color(Qt::blue)
{
    resize(80,80);
    setAttribute(Qt::WA_TranslucentBackground);

//    appendProInfo("Height","int","宽度");
    appendProVariantMap("Color","QColor","颜色");
}

CircleWidget::~CircleWidget()
{

}

void CircleWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QPen(color,4,Qt::SolidLine));
    painter.drawEllipse(2,2,width()-4,height()-4);
    painter.end();

    QWidget::paintEvent(e);
}
