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
};

class CircleWidget:public ControlBaseWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor Color READ  getColor WRITE setColor)
public:
    CircleWidget();
    ~CircleWidget();

    const QColor getColor(){return color;}
    void setColor(const QColor& c){color=c;}
protected:
    void paintEvent(QPaintEvent *);
private:
    QColor color;
};

#endif // CIRCLE_H
