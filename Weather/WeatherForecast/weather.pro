#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T11:29:33
#
#-------------------------------------------------

QT       += core gui charts

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtstart
TEMPLATE = app
LIBS +=  -lcurl -l json -lboost_iostreams -lboost_system -lrt

SOURCES += \
    src/FileHandler.cpp \
    src/Helper.cpp \
    src/MessagingHandler.cpp \
    src/Plotter.cpp \
    src/ProgramHandler.cpp \
    src/WeatherGeneral.cpp \
    src/WeatherOWM.cpp \
    src/WeatherYahoo.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS  += \
    inc/FileHandler.h \
    inc/Helper.h \
    inc/MessagingHandler.h \
    inc/Plotter.h \
    inc/ProgramHandler.h \
    inc/WeatherAPI.h \
    inc/WeatherGeneral.h \
    inc/WeatherOWM.h \
    inc/WeatherYahoo.h \
    mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    data/owm.city.list.json \
    src/a.out \
    src/README
