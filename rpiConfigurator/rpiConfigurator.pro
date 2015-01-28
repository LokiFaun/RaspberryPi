#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiConfigurator
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += configurationtabfactory.cpp configurationwizardfactory.cpp iconfigurationwidget.cpp serviceconfigurationwidget.cpp servicemonitorconfigurationwidget.cpp MainWindow.cpp main.cpp
HEADERS   += configurationtabfactory.h configurationwizardfactory.h iconfigurationwidget.h serviceconfigurationwidget.h servicemonitorconfigurationwidget.h MainWindow.h
FORMS     += MainWindow.ui
RESOURCES += 

include($$lower($$join(CONFIGNAME,,,.pro)))

INCLUDEPATH += $$PWD/../../Qt-Solutions/QtService/src

LIBS += -L$$OUT_PWD/../rpiBase/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/../rpiLogger/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

LIBS += -L$$OUT_PWD/../rpiConfig/$$DESTDIR -lrpiConfig

INCLUDEPATH += $$PWD/../rpiConfig
DEPENDPATH += $$PWD/../rpiConfig

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
