#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T14:56:06
#
#-------------------------------------------------

VERSION = 1.0.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core
QT       -= gui

TARGET = rpiServiceMonitor
CONFIG   += console qt
CONFIG   -= app_bundle

TEMPLATE = app

include($$lower($$join(CONFIGNAME,,,.pro)))

INCLUDEPATH += $$PWD/../../Qt-Solutions/QtService/src

SOURCES += main.cpp monitorconfig.cpp service.cpp servicemonitor.cpp

HEADERS += monitorconfig.h service.h servicemonitor.h

LIBS += -L$$OUT_PWD/../rpiBase/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/../rpiLogger/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
