QT       += core gui widgets

TARGET = LayoutSample
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    label.cpp \
    vboxlayout.cpp

HEADERS += \
        widget.h \
    label.h \
    vboxlayout.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
