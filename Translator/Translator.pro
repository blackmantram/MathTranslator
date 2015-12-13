#-------------------------------------------------
#
# Project created by QtCreator 2015-12-13T18:46:11
#
#-------------------------------------------------

QT       -= gui

TARGET = Translator
TEMPLATE = lib

DEFINES += TRANSLATOR_LIBRARY

SOURCES += translator.cpp

HEADERS += translator.h\
        translator_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
