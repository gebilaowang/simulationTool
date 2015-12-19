#ifndef CONTROLLISTWIDGET_H
#define CONTROLLISTWIDGET_H

#include <QWidget>
#include <QDockWidget>

class Widget;
class QTreeView;
class QTreeWidget;
class ControlListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlListWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
private:
QTreeWidget *tree;
};


#endif // CONTROLLISTWIDGET_H
