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
    controlbasewidget.cpp \
    controlgraphicsproxywidget.cpp

HEADERS += baseclass.h\
        baseclass_global.h \
    factorybaseclass.h \
    controlbasewidget.h \
    controlgraphicsproxywidget.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core
