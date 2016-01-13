#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T12:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controllistwidget.cpp \
    warningwidget.cpp \
    propertytreewidget.cpp \
    centralwidget.cpp

HEADERS  += mainwindow.h \
    controllistwidget.h \
    warningwidget.h \
    propertytreewidget.h \
    centralwidget.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BaseClass/release/ -lBaseClass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BaseClass/debug/ -lBaseClass
else:unix: LIBS += -L$$OUT_PWD/../BaseClass/ -lBaseClass

INCLUDEPATH += $$PWD/../BaseClass
DEPENDPATH += $$PWD/../BaseClass

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ControlFactory/release/ -lControlFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ControlFactory/debug/ -lControlFactory
else:unix: LIBS += -L$$OUT_PWD/../ControlFactory/ -lControlFactory

INCLUDEPATH += $$PWD/../ControlFactory
DEPENDPATH += $$PWD/../ControlFactory

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core
