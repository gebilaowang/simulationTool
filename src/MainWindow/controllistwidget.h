#ifndef CONTROLLISTWIDGET_H
#define CONTROLLISTWIDGET_H

#include <QWidget>
//#include <QModelIndex>

class QModelIndex;
class Widget;
class QTreeView;
class QTreeWidget;
class ControlListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlListWidget(QWidget *parent = 0);
    ~ControlListWidget();
private:
    void createUI();
    void createConnects();
private slots:
    //鼠标拖拽事件
    void slotStartDarg();
private:
    QTreeWidget *tree;
};


#endif // CONTROLLISTWIDGET_H
