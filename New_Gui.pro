#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T13:54:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = New_Gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    edge.cpp \
    node.cpp \
    scene.cpp \
    mst.cpp

HEADERS  += mainwindow.h \
    edge.h \
    node.h \
    scene.h \
    mst.h

FORMS    += mainwindow.ui
