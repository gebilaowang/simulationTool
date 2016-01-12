#ifndef CONTROLBASEWIDGET_H
#define CONTROLBASEWIDGET_H

#include <QWidget>
#include <QGraphicsProxyWidget>

class ControlBaseWidget : public QGraphicsProxyWidget
{
    Q_OBJECT
public:
    explicit ControlBaseWidget(QGraphicsProxyWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CONTROLBASEWIDGET_H
