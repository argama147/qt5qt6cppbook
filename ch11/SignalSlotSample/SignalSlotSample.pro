QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalSlotSample
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#CONFIG += c++11
CONFIG += c++14

SOURCES += \
    main.cpp \
    widget.cpp \
    receiver.cpp \
    sender.cpp \
    connector.cpp \
    qt4styleconnector.cpp \
    qt5styleconnector.cpp \
    lamdastyle1connector.cpp \
    lamdastyle2connector.cpp

HEADERS += \
    widget.h \
    receiver.h \
    sender.h \
    connector.h \
    qt4styleconnector.h \
    qt5styleconnector.h \
    lamdastyle1connector.h \
    lamdastyle2connector.h

FORMS += \
    widget.ui
