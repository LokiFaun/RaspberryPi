#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

include(../version.pri)

QT += core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiComm
TEMPLATE = lib

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += publisher.cpp
HEADERS   += publisher.h rpicomm_global.h
FORMS     += 
RESOURCES += 

include($$lower($$join(CONFIGNAME,,,.pro)))

DEFINES += RPICOMM_LIBRARY

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

LIBS += -lmosquittopp
