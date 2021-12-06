TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -ltins

SOURCES += \
        airodump.cpp \
        main.cpp

HEADERS += \
    airodump.h
