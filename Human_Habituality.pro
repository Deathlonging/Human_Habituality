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
    character.cpp \
    mapview.cpp \
    mapobject.cpp \
    moveablemapobject.cpp \
    nonmoveablemapobject.cpp \
    Shapes/shape.cpp \
    Shapes/circleshape.cpp \
    Shapes/rectangleshape.cpp \
    Shapes/groupshape.cpp \
    color.cpp

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
    character.h \
    idirectionable.h \
    mapview.h \
    imoveable.h \
    mapobject.h \
    moveablemapobject.h \
    nonmoveablemapobject.h \
    controlelements.h \
    Shapes/shape.h \
    Shapes/circleshape.h \
    Shapes/rectangleshape.h \
    Shapes/groupshape.h \
    color.h

