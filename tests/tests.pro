TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT  += sql

SOURCES += \
        main.cpp \
    designapp.cpp \
    bbdd.cpp

HEADERS += \
    designapp.h \
    bbdd.h
