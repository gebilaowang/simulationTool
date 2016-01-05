#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include "basewidget.h"

class Circle : public BaseWidget
{
    Q_OBJECT
public:
    explicit Circle(BaseWidget *parent=0);
    ~Circle();
    
protected:
    void paintEvent(QPaintEvent *);
signals:
    
public slots:
    
};

#endif // CIRCLE_H
