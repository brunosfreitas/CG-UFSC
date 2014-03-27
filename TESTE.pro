#-------------------------------------------------
#
# Project created by QtCreator 2014-03-25T18:13:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TESTE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    coordenada.cc \
    ponto.cpp \
    reta.cpp \
    mundo.cpp \
    objetografico.cpp \
    viewport.cpp

HEADERS  += mainwindow.h \
    coordenada.h \
    ../ponto.h \
    ponto.h \
    reta.h \
    mundo.h \
    objetografico.h \
    viewport.h

FORMS    += mainwindow.ui
