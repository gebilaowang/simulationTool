#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T09:39:17
#
#-------------------------------------------------
include(../../SimulationTool.pri)
#DESTDIR = $$ST_LIB_PATH

TARGET = ControlFactory
TEMPLATE = lib

DEFINES += CONTROLFACTORY_LIBRARY

SOURCES += controlfactory.cpp \
    circle.cpp \
    rectangle.cpp

HEADERS += controlfactory.h\
        controlfactory_global.h \
    circle.h \
    rectangle.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


unix|win32: LIBS += -L$$OUT_PWD/../BaseClass/ -lBaseClass

INCLUDEPATH += $$PWD/../BaseClass
DEPENDPATH += $$PWD/../BaseClass
