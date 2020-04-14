#-------------------------------------------------
#
# Project created by QtCreator 2020-03-14T11:08:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = micromouse
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++14

SOURCES += \
        main.cpp \
        GUI/dialogs/src/mainwindow.cpp \
        logic/Board/src/boardgenerator.cpp \
        GUI/objects/src/gboard.cpp \
        logic/Board/src/board.cpp \
        logic/Mouse/src/mouse.cpp \
        GUI/objects/src/gmouse.cpp \
    logic/Mouse/src/sensor.cpp \
    logic/Mouse/src/boardmap.cpp \
    logic/Board/src/cell.cpp \
    GUI/objects/src/gsensor.cpp \
    GUI/dialogs/src/startdialog.cpp \
    GUI/dialogs/src/newboarddialog.cpp \
    logic/micromouse.cpp \
    logic/Board/src/fileboard.cpp

HEADERS += \
        GUI/dialogs/include/mainwindow.h \
        logic/Board/include/boardgenerator.h \
        GUI/objects/include/gboard.h \
        logic/Board/include/board.h \
        logic/Mouse/include/mouse.h \
        GUI/objects/include/gmouse.h \
    logic/Mouse/include/sensor.h \
    logic/Mouse/include/position.h \
    logic/Mouse/include/boardmap.h \
    logic/Board/include/cell.h \
    GUI/objects/include/gsensor.h \
    GUI/dialogs/include/startdialog.h \
    GUI/dialogs/include/newboarddialog.h \
    logic/micromouse.h \
    logic/Board/include/fileboard.h

FORMS += \
        GUI/forms/mainwindow.ui \
    GUI/forms/startdialog.ui \
    GUI/forms/newboarddialog.ui

RESOURCES += \
    GUI/resources/resources.qrc
