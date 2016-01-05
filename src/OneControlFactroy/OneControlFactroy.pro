#-------------------------------------------------
#
# Project created by QtCreator 2016-01-05T11:03:27
#
#-------------------------------------------------
include(../../SimulationTool.pri)
DESTDIR = ST_LIB_PATH

TARGET = OneControlFactroy
TEMPLATE = lib

DEFINES += ONECONTROLFACTROY_LIBRARY

SOURCES += onecontrolfactroy.cpp

HEADERS += onecontrolfactroy.h\
        onecontrolfactroy_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
