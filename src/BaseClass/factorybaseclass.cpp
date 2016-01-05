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

ControlBaseWidget *FactoryBaseClass::getProduct(const QString)
{

}
