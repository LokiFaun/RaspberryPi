#ifndef RPIBASE_GLOBAL_H
#define RPIBASE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RPIBASE_LIBRARY)
#  define RPIBASESHARED_EXPORT Q_DECL_EXPORT
#else
#  define RPIBASESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RPIBASE_GLOBAL_H
