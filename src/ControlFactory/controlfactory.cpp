#include "controlfactory.h"
#include "circle.h"
#include "rectangle.h"

ControlFactory::ControlFactory()
{
    initProductList();
}

ControlFactory::~ControlFactory()
{

}

 ControlBaseWidget* ControlFactory::getProduct(const QString nameStr)
{
    if(nameStr.contains("Circle"))
    {
        return new CircleWidget;
    }
//    else if(nameStr.contains("Rectangle"))
//    {
//        return new Rectangle;
//    }
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
    productNameList.append("Rectangle1");
    productNameList.append("Rectangle2");
    productNameList.append("Rectangle3");
    productNameList.append("Rectangle4");
    productNameList.append("Rectangle5");
    productNameList.append("Rectangle6");
    productNameList.append("Rectangle7");
}
