#include "factorybaseclass.h"

FactoryBaseClass::FactoryBaseClass(QObject *parent) :
    QObject(parent)
{
}

FactoryBaseClass::~FactoryBaseClass()
{

}

QStringList FactoryBaseClass::getControlNameList()
{

}

ControlGraphicsProxyWidget *FactoryBaseClass::getProduct(const QString)
{

}
