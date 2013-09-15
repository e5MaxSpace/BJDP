#-------------------------------------------------
#
# Project created by QtCreator 2013-08-18T13:55:04
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = testatm
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../ATM/ATM.pri)

SOURCES += \
    testatm.cpp

#DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS +=

OTHER_FILES += \
    requirements.txt
