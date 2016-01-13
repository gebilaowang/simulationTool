#ifndef BASECLASS_H
#define BASECLASS_H

#include "baseclass_global.h"
#include <QWidget>

class BASECLASSSHARED_EXPORT BaseClass:public QWidget
{
        Q_OBJECT
public:
    BaseClass(QWidget*parent=0);
    virtual ~BaseClass();
};

#endif // BASECLASS_H
