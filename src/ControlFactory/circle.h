#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include "controlbasewidget.h"

class Circle : public ControlBaseWidget
{
    Q_OBJECT
public:
    explicit Circle(ControlBaseWidget *parent=0);
    ~Circle();
    
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
};

#endif // CIRCLE_H
