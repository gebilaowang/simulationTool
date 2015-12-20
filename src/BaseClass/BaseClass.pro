#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T09:38:25
#
#-------------------------------------------------

TARGET = BaseClass
TEMPLATE = lib

DEFINES += BASECLASS_LIBRARY

SOURCES += baseclass.cpp

HEADERS += baseclass.h\
        baseclass_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
