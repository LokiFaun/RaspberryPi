#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:19:28
#
#-------------------------------------------------

VERSION = 1.0.0

QT       -= gui
CONFIG += plugin

TARGET = rpiBase
TEMPLATE = lib

DEFINES += RPIBASE_LIBRARY
DEFINES += QTJSONSETTINGS_EXPORTS
DEFINES += QT_QTSERVICE_EXPORT

include(../../qtjsonsettings/qtjsonsettings.pri)
include(../../Qt-Solutions/QtService/src/QtService.pri)

SOURCES += \
    exception.cpp

HEADERS +=\
        rpibase_global.h \
    name_defs.h \
    command_defs.h \
    exception.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
