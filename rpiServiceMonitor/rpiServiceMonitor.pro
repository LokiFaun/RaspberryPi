#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T14:56:06
#
#-------------------------------------------------

include(../version.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core
QT       -= gui

TARGET = rpiServiceMonitor
CONFIG   += console qt
CONFIG   -= app_bundle

TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

include($$lower($$join(CONFIGNAME,,,.pro)))

SOURCES += rpiServiceMonitor.cpp service.cpp servicemonitor.cpp
HEADERS += service.h servicemonitor.h

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR

#include project libraries

INCLUDEPATH += $$PWD/../thirdparty/Qt-Solutions/QtService/src

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiConfig

INCLUDEPATH += $$PWD/../rpiConfig
DEPENDPATH += $$PWD/../rpiConfig

LIBS += -L$$PWD/../thirdparty/qslog/build-QsLogShared
INCLUDEPATH += $$PWD/../thirdparty/qslog
DEPENDPATH += $$PWD/../thirdparty/qslog
win32 {
    LIBS += -lQsLog2
} else {
    LIBS += -lQsLog
}
