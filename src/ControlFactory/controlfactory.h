#ifndef CONTROLFACTORY_H
#define CONTROLFACTORY_H

#include "controlfactory_global.h"
#include "baseclass.h"
#include "basewidget.h"


class CONTROLFACTORYSHARED_EXPORT ControlFactory:public BaseClass
{
public:
    ControlFactory();
    ~ControlFactory();

    BaseWidget *getProduct(const QString);

private:
    void initProductList();
private:
    QStringList productNameList;
};

#endif // CONTROLFACTORY_H
