QT += core
QT -= gui

CONFIG += c++11

TARGET = library
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    user.cpp

HEADERS += \
    user.h
