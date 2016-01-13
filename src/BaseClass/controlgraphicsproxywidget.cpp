#include "controlgraphicsproxywidget.h"

ControlGraphicsProxyWidget::ControlGraphicsProxyWidget(QGraphicsProxyWidget *parent) :
    QGraphicsProxyWidget(parent)
{
    setSelected(QGraphicsItem::ItemIsSelectable);
}
