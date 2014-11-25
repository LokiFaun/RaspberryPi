#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T20:30:48
#
#-------------------------------------------------

VERSION = 1.0.0

QT       -= gui
CONFIG += plugin

TARGET = rpiLogger
TEMPLATE = lib

DEFINES += RPILOGGER_LIBRARY

SOURCES += rpilogger.cpp \
    debugappender.cpp \
    logmanager.cpp \
    loggerconfiguration.cpp

HEADERS += rpilogger.h\
        rpilogger_global.h \
    debugappender.h \
    iappender.h \
    logmanager.h \
    loggerconfiguration.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../rpiBase/release/ -lrpiBase1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../rpiBase/debug/ -lrpiBase1
else:unix: LIBS += -L$$OUT_PWD/../rpiBase/ -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

unix {
    target.path = /usr/lib
    INSTALLS += target
}
