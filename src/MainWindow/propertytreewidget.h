#ifndef PROPERTYTREEWIDGET_H
#define PROPERTYTREEWIDGET_H

#include <QWidget>


class QTreeWidget;

class PropertyTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyTreeWidget(QWidget *parent = 0);
    
public slots:
    void slotGetControlWidget(QWidget*);
private:
    void createUI();
private:
    QTreeWidget *treeWidget;
};



class PropertyTestWidget:public QWidget
{
    Q_OBJECT
public:
    explicit PropertyTestWidget();

private:
    void createUI();
};

#endif // PROPERTYTREEWIDGET_H
