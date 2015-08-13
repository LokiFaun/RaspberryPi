#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:30:48
#
#-------------------------------------------------

include(../version.pri)

QT += core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiLogger
TEMPLATE = lib

SOURCES += logmanager.cpp rpilogger.cpp

HEADERS += logmanager.h rpilogger.h rpilogger_global.h

include($$lower($$join(CONFIGNAME,,,.pro)))

DEFINES += RPILOGGER_LIBRARY

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

DEFINES += QSLOG_IS_SHARED_LIBRARY_IMPORT

LIBS += -L$$PWD/../thirdparty/qslog/build-QsLogShared
INCLUDEPATH += $$PWD/../thirdparty/qslog
DEPENDPATH += $$PWD/../thirdparty/qslog
win32 {
    LIBS += -lQsLog2
} else {
    LIBS += -lQsLog
}

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
