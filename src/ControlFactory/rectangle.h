#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include "basewidget.h"

class Rectangle : public BaseWidget
{
    Q_OBJECT
public:
    explicit Rectangle(BaseWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
};

#endif // RECTANGLE_H
