#include "controlbasewidget.h"

ControlBaseWidget::ControlBaseWidget(QWidget *parent) :
    QWidget(parent)
{
    insertProInfo("Width","int","宽度");
    insertProInfo("Height","int","宽度");
}

ControlBaseWidget::~ControlBaseWidget()
{

}

void ControlBaseWidget::insertProInfo(const QString &name, const QString &type, const QString &chName)
{
    PropertyInfo info;
    info.name=name;
    info.type=type;
    info.chName=chName;

    proInfoList.append(info);
}
