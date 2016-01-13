#include "controlbasewidget.h"

ControlBaseWidget::ControlBaseWidget(QWidget *parent) :
    QWidget(parent)
{
    appendProVariantMap("Width","int","宽度");
    appendProVariantMap("Height","int","高度");
}

ControlBaseWidget::~ControlBaseWidget()
{

}

QMap<QString, PropertyInfo> ControlBaseWidget::getProVariantMap()
{
    return proVariantMap;
}

void ControlBaseWidget::appendProVariantMap(const QString &name, const QString &type, const QString &chName)
{
    PropertyInfo info;
    info.name=name;
    info.type=type;
    info.chName=chName;

    proVariantMap.insert(info.name,info);
}
