TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

SOURCES += main.cpp \
    game.cpp \
    map.cpp \
    visitor.cpp \
    application.cpp \
    mapblock.cpp \
    debughandling.cpp \
    utils.cpp \
    human.cpp \
    character.cpp \
    mapview.cpp \
    mapobject.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    game.h \
    map.h \
    visitor.h \
    idrawable.h \
    application.h \
    debughandling.h \
    mapblock.h \
    ipositionable.h \
    utils.h \
    iupdateable.h \
    human.h \
    character.h \
    idirectionable.h \
    mapview.h \
    imoveable.h \
    mapobject.h

