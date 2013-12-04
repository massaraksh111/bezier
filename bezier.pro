QT += widgets

QMAKE_CXXFLAGS_WARN_ON += -Wextra -Wall -Wno-sign-compare
QMAKE_CXXFLAGS += -pipe -std=c++11

SOURCES += \
    main.cpp \
    view.cpp \
    singleline.cpp \
    bezierline.cpp

HEADERS += \
    view.h \
    singleline.h \
    bezierline.h \
    complexline.h
