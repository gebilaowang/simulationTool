#include "controlfactory.h"
#include "circle.h"
#include "rectangle.h"

ControlFactory::ControlFactory()
{
}

ControlFactory::~ControlFactory()
{

}

ControlBaseWidget *ControlFactory::getProduct(const QString nameStr)
{
    if(nameStr.contains("Circle"))
    {
        return new Circle;
    }
    else if(nameStr.contains("Rectangle"))
    {
        return new Rectangle;
    }
    else
        return NULL;
}

QStringList ControlFactory::getControlNameList()
{

}

void ControlFactory::initProductList()
{
    productNameList.append("Circle");
    productNameList.append("Rectangle");
}
