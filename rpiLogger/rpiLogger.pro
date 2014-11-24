#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:30:48
#
#-------------------------------------------------

QT       -= gui

TARGET = rpiLogger
TEMPLATE = lib

DEFINES += RPILOGGER_LIBRARY

SOURCES += rpilogger.cpp

HEADERS += rpilogger.h\
        rpilogger_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
