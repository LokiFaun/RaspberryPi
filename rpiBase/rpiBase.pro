#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:19:28
#
#-------------------------------------------------

QT       -= gui

TARGET = rpiBase
TEMPLATE = lib

DEFINES += RPIBASE_LIBRARY

SOURCES +=

HEADERS += singleton.h\
        rpibase_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
