TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DSString.cpp \
    tests.cpp \
    metricanalyzer.cpp \
    m1.cpp \
    m2.cpp \
    m3.cpp \
    m4.cpp \
    m5.cpp \
    file.cpp \
    hashtable.cpp \
    variable.cpp

HEADERS += \
    catch.hpp \
    DSString.h \
    metricanalyzer.h \
    m1.h \
    m2.h \
    m3.h \
    m4.h \
    m5.h \
    avltree.h \
    vector.h \
    file.h \
    hashtable.h \
    linkedlist.h \
    variable.h

