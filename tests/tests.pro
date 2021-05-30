include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
QT += core

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += main.cpp  \
    ../app/ball.cpp \
    ../app/collision.cpp \
    ../app/game.cpp \
    ../app/panel.cpp


INCLUDEPATH += ../app   

HEADERS += \
    ../app/ball.h \
    ../app/collision.h \
    ../app/game.h \
    ../app/panel.h \
    testball.h \
    testcollision.h \
    testgame.h \
    testpanel.h
