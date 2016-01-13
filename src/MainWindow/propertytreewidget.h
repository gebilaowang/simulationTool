#ifndef PROPERTYTREEWIDGET_H
#define PROPERTYTREEWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVariant>
#include "definetion.h"

class QStandardItemModel;
class QTreeView;
class ControlBaseWidget;
class QTreeWidget;

class PropertyTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyTreeWidget(QWidget *parent = 0);
    
public slots:
    void slotGetControlTarget(QWidget*);
private:
    void createUI();
    void createPropertyTree();

    void createCommonModel();
private:
    QMap<QString,PropertyInfo> proVariantMap;

    QTreeWidget *commonTree;
    QTreeView *commonTreeView;
    QStandardItemModel *commonModel;
};



class PropertyTestWidget:public QWidget
{
    Q_OBJECT
public:
    explicit PropertyTestWidget();
signals:
    void sigControlTarget(QWidget*);
private:
    void createUI();
};

#endif // PROPERTYTREEWIDGET_H
