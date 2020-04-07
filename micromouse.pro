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
        mainwindow.cpp \
        boardgenerator.cpp \
        gboard.cpp \
        board.cpp \
        mouse.cpp \
        gmouse.cpp \
    sensor.cpp \
    boardmap.cpp \
    cell.cpp \
    gsensor.cpp \
    startdialog.cpp \
    newboarddialog.cpp \
    micromouse.cpp

HEADERS += \
        mainwindow.h \
        boardgenerator.h \
        gboard.h \
        board.h \
        mouse.h \
        gmouse.h \
    sensor.h \
    position.h \
    boardmap.h \
    cell.h \
    gsensor.h \
    startdialog.h \
    newboarddialog.h \
    micromouse.h

FORMS += \
        mainwindow.ui \
    startdialog.ui \
    newboarddialog.ui

RESOURCES += \
    resources.qrc
