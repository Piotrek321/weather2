QT += testlib widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase
LIBS +=  -lcurl -l json -lboost_iostreams -lboost_system -lrt

TEMPLATE = app

SOURCES +=  tst_test1.cpp \
    ../WeatherForecast/mainwindow.cpp \
    ../WeatherForecast/src/FileHandler.cpp \
    ../WeatherForecast/src/Helper.cpp \
    ../WeatherForecast/src/MessagingHandler.cpp \
    ../WeatherForecast/src/Plotter.cpp \
    ../WeatherForecast/src/ProgramHandler.cpp \
    ../WeatherForecast/src/WeatherGeneral.cpp \
    ../WeatherForecast/src/WeatherOWM.cpp \
    ../WeatherForecast/src/WeatherYahoo.cpp

HEADERS += \
    ../WeatherForecast/mainwindow.h \
    ../WeatherForecast/inc/FileHandler.h \
    ../WeatherForecast/inc/gnuplot-iostream.h \
    ../WeatherForecast/inc/Helper.h \
    ../WeatherForecast/inc/MessagingHandler.h \
    ../WeatherForecast/inc/Plotter.h \
    ../WeatherForecast/inc/ProgramHandler.h \
    ../WeatherForecast/inc/WeatherAPI.h \
    ../WeatherForecast/inc/WeatherGeneral.h \
    ../WeatherForecast/inc/WeatherOWM.h \
    ../WeatherForecast/inc/WeatherYahoo.h

DISTFILES += \
    ../WeatherForecast/src/README
