#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:30:48
#
#-------------------------------------------------

VERSION = 1.0.0


QT += core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiLogger
TEMPLATE = lib

SOURCES += debugappender.cpp loggerconfiguration.cpp logmanager.cpp rpilogger.cpp

HEADERS += debugappender.h iappender.h loggerconfiguration.h logmanager.h rpilogger.h rpilogger_global.h

include($$lower($$join(CONFIGNAME,,,.pro)))

DEFINES += RPILOGGER_LIBRARY

LIBS += -L$$OUT_PWD/../rpiBase/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
