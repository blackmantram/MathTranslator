#-------------------------------------------------
#
# Project created by QtCreator 2015-12-13T18:44:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Translator/release/ -lTranslator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Translator/debug/ -lTranslator
else:unix: LIBS += -L$$OUT_PWD/../Translator/ -lTranslator

INCLUDEPATH += $$PWD/../Translator
DEPENDPATH += $$PWD/../Translator
