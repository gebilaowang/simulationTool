#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T09:38:25
#
#-------------------------------------------------
include(../../SimulationTool.pri)
#DESTDIR = $$ST_LIB_PATH

TARGET = BaseClass
TEMPLATE = lib

DEFINES += BASECLASS_LIBRARY

SOURCES += baseclass.cpp \
    factorybaseclass.cpp \
    controlbasewidget.cpp

HEADERS += baseclass.h\
        baseclass_global.h \
    factorybaseclass.h \
    controlbasewidget.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
