#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T14:56:06
#
#-------------------------------------------------

VERSION = 1.0.0

QT       += core
QT       -= gui

TARGET = rpiServiceMonitor
CONFIG   += console qt
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../../Qt-Solutions/QtService/src

SOURCES += main.cpp \
    servicemonitor.cpp \
    service.cpp \
    monitorconfig.cpp

HEADERS += \
    servicemonitor.h \
    service.h \
    monitorconfig.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../rpiBase/release/ -lrpiBase1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../rpiBase/debug/ -lrpiBase1
else:unix: LIBS += -L$$OUT_PWD/../rpiBase/ -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../rpiLogger/release/ -lrpiLogger1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../rpiLogger/debug/ -lrpiLogger1
else:unix: LIBS += -L$$OUT_PWD/../rpiLogger/ -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger
