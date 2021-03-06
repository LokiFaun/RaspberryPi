#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

include(../version.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpiConfigurator
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += configurationtabfactory.cpp configurationwizardfactory.cpp iconfigurationwidget.cpp serviceconfigurationwidget.cpp servicemonitorconfigurationwidget.cpp MainWindow.cpp rpiConfigurator.cpp
HEADERS   += configurationtabfactory.h configurationwizardfactory.h iconfigurationwidget.h serviceconfigurationwidget.h servicemonitorconfigurationwidget.h MainWindow.h
FORMS     += MainWindow.ui
RESOURCES += 

include($$lower($$join(CONFIGNAME,,,.pro)))

INCLUDEPATH += $$PWD/../thirdparty/Qt-Solutions/QtService/src

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiBase

INCLUDEPATH += $$PWD/../rpiBase
DEPENDPATH += $$PWD/../rpiBase

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiLogger

INCLUDEPATH += $$PWD/../rpiLogger
DEPENDPATH += $$PWD/../rpiLogger

LIBS += -L$$OUT_PWD/$$DESTDIR -lrpiConfig

INCLUDEPATH += $$PWD/../rpiConfig
DEPENDPATH += $$PWD/../rpiConfig

LIBS += -L$$PWD/../thirdparty/qslog/build-QsLogShared
INCLUDEPATH += $$PWD/../thirdparty/qslog
DEPENDPATH += $$PWD/../thirdparty/qslog
win32 {
    LIBS += -lQsLog2
} else {
    LIBS += -lQsLog
}

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
