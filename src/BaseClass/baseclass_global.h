#ifndef BASECLASS_GLOBAL_H
#define BASECLASS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BASECLASS_LIBRARY)
#  define BASECLASSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BASECLASSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BASECLASS_GLOBAL_H
