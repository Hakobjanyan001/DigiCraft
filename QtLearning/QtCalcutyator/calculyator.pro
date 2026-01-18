QT += core gui widgets

CONFIG += c++17

TARGET = MyCalculator
TEMPLATE = app

SOURCES += \
	src/main.cpp \
	src/simple_window.cpp

HEADERS += \
	include/simple_window.h

INCLUDEPATH += include

OBJECTS_DIR = build
