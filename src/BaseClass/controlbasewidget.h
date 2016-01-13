#ifndef CONTROLBASEWIDGET_H
#define CONTROLBASEWIDGET_H

#include <QWidget>
#include "definetion.h"

class ControlBaseWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int Width READ getWidth WRITE setWidth)
    Q_PROPERTY(int Height READ getHeight WRITE setHeight)
public:
    explicit ControlBaseWidget(QWidget *parent = 0);
    virtual ~ControlBaseWidget();

    QMap<QString,PropertyInfo> getProVariantMap();
    
    void setWidth(const int w){setWidth(w);}
    int getWidth(){return width();}

    void setHeight(const int h){setHeight(h);}
    int getHeight(){return height();}
protected:
    void appendProVariantMap(const QString&name,const QString&type,const QString&chName);
private:
    QMap<QString,PropertyInfo> proVariantMap;
};

#endif // CONTROLBASEWIDGET_H
