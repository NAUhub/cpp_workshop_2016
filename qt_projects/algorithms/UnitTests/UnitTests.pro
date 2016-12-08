#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T09:26:52
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_sorttest
CONFIG   += testcase
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

SOURCES += \
    ../../../src/algorithms/UnitTests/tst_sorttest.cpp \
    ../../../src/algorithms/sort/sort.cpp

HEADERS += \
    ../../../src/algorithms/sort/sort.h \
    ../../../src/algorithms/sort/bubblesorter.h \
    ../../../src/algorithms/sort/mergesorter.h \
    ../../../src/algorithms/sort/shakesorter.h

INCLUDEPATH += ../../../src/algorithms/sort
