#-------------------------------------------------
#
# Project created by QtCreator 2019-04-14T16:39:18
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RMS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    rmshandler.cpp \
    socket.cpp \
    usecase/manage_order.cpp \
    domain/seat_list.cpp \
    domain/seat.cpp \
    domain/meal.cpp \
    domain/meal_list.cpp \
    domain/order.cpp \
    domain/seat_order.cpp \
    domain/seat_order_list.cpp

HEADERS += \
    mainwindow.h \
    rmshandler.h \
    socket.h \
    usecase/manage_order.h \
    domain/seat_list.h \
    domain/seat.h \
    domain/meal.h \
    domain/meal_list.h \
    domain/order.h \
    domain/seat_order.h \
    domain/seat_order_list.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
