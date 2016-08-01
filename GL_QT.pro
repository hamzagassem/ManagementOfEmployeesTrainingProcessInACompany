#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T18:50:07
#
#-------------------------------------------------

QT += QGraphicsWebView
QT += webkitwidgets
QT       += core gui sql        webkit network script

TARGET = GL_QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    e_menu.cpp \
    cs_menu.cpp \
    a_menu.cpp

HEADERS  += mainwindow.h \
    connection.h \
    e_menu.h \
    cs_menu.h \
    a_menu.h

FORMS    += mainwindow.ui \
    e_menu.ui \
    cs_menu.ui \
    a_menu.ui

RESOURCES += \
    ressource.qrc

OTHER_FILES += \
    style.qss
