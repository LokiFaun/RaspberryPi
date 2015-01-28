#ifndef RPILOGGER_GLOBAL_H
#define RPILOGGER_GLOBAL_H

#pragma once

#include <QtCore/qglobal.h>

#if defined(RPILOGGER_LIBRARY)
#  define RPILOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RPILOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RPILOGGER_GLOBAL_H
