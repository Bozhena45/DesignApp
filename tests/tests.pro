TEMPLATE = app
QT -= gui
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    designapp.cpp \
    bbdd.cpp

HEADERS += \
    designapp.h \
    bbdd.h
