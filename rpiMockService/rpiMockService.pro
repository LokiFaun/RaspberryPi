#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

QT       += core
QT       -= gui
CONFIG   += console qt
CONFIG   -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiMockService
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += mockservice.cpp rpiMockService.cpp
HEADERS   += mockservice.h
FORMS     += 
RESOURCES += 

include($$lower($$join(CONFIGNAME,,,.pro)))

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR

#include project libraries

INCLUDEPATH += $$PWD/../../Qt-Solutions/QtService/src

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiConfig

INCLUDEPATH += $$PWD/../rpiConfig
DEPENDPATH += $$PWD/../rpiConfig

LIBS += -L$$PWD/../../qslog/build-QsLogShared
INCLUDEPATH += $$PWD/../../qslog
DEPENDPATH += $$PWD/../../qslog
win32 {
    LIBS += -lQsLog2
} else {
    LIBS += -lQsLog
}
