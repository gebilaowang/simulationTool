#ifndef CONTROLFACTORY_H
#define CONTROLFACTORY_H

#include "controlfactory_global.h"
#include "baseclass.h"
#include "controlbasewidget.h"
#include "factorybaseclass.h"
#include "controlgraphicsproxywidget.h"

class CONTROLFACTORYSHARED_EXPORT ControlFactory:public FactoryBaseClass
{
public:
    ControlFactory();
    ~ControlFactory();

    ControlGraphicsProxyWidget *getProduct(const QString);
    QStringList getControlNameList();
private:
    void initProductList();
private:
    QStringList productNameList;
};

#endif // CONTROLFACTORY_H
