#ifndef DEFINETION_H
#define DEFINETION_H

#include <QObject>
#include <QVariant>

struct PropertyInfo
{
    PropertyInfo(){variant.clear();}

    QString name;
    QString type;
    QString chName;

    QVariant variant;
};

#endif // DEFINETION_H
