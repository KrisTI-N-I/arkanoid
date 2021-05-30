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

SOURCES += main.cpp 
#     ../app/load.cpp \
#     ../app/save.cpp \
#     ../app/show.cpp \
#     ../app/showunderscores.cpp \
#     ../app/text/append_line.cpp \
#     ../app/text/create_text.cpp \
#     ../app/text/m.cpp \
#     ../app/text/mpweb.cpp \
#     ../app/text/process_forward.cpp \
#     ../app/text/remove_all.cpp \
#     ../app/text/rn.cpp


# HEADERS += save_test.h \
#     ../app/common.h \
#     ../app/text/_text.h \
#     ../app/text/text.h \
#     m_test.h \
#     mpweb.h \
#     rn_test.h \
#     save_test.h \
#     tests.h \
#     under_test.h

INCLUDEPATH += ../app   
