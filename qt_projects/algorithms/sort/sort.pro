TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../../src/algorithms/sort/sort.cpp \
    ../../../src/algorithms/sort/main.cpp

HEADERS += \
    ../../../src/algorithms/sort/sort.h \
    ../../../src/algorithms/sort/shakesorter.h \
    ../../../src/algorithms/sort/mergesorter.h \
    ../../../src/algorithms/sort/bubblesorter.h
