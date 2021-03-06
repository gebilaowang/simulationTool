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


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BaseClass/release/ -lBaseClass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BaseClass/debug/ -lBaseClass
else:unix: LIBS += -L$$OUT_PWD/../BaseClass/ -lBaseClass

INCLUDEPATH += $$PWD/../BaseClass
DEPENDPATH += $$PWD/../BaseClass
