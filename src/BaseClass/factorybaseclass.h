#ifndef FACTORYBASECLASS_H
#define FACTORYBASECLASS_H

#include <QObject>
#include "controlbasewidget.h"
#include "controlgraphicsproxywidget.h"

class FactoryBaseClass
{
public:
    ~FactoryBaseClass();

    virtual QStringList getControlNameList();
    virtual ControlBaseWidget *getProduct(const QString);
};

#endif // FACTORYBASECLASS_H
