QT += core gui network widgets

CONFIG += c++17

TARGET = Monitor
TEMPLATE = app

SOURCES += \
	agent_cpp/main.cpp \
	agent_cpp/src/SystemAgent.cpp

HEADERS += \
	agent_cpp/include/SystemAgent.h

INCLUDEPATH += agent_cpp/include

OBJECTS_DIR = build
