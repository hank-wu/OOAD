#-------------------------------------------------
#
# Project created by QtCreator 2019-04-14T16:39:18
#
#-------------------------------------------------

QT       += core gui    \
            network \
            sql

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
    domain/seat_order_list.cpp \
    domain/menu.cpp \
    domain/order_item.cpp \
    domain/bill.cpp \
    domain/receipt.cpp \
    dao/menu_dao.cpp \
    dao/seat_dao.cpp \
    domain/order_pair.cpp \
    customer_manage.cpp \
    login_page.cpp \
    dialog.cpp \
    receipt_dilog.cpp \
    staff_manage.cpp \
    host_dialog.cpp

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
    domain/seat_order_list.h \
    domain/menu.h \
    domain/order_item.h \
    domain/bill.h \
    domain/receipt.h \
    dao/menu_dao.h \
    dao/seat_dao.h \
    domain/order_pair.h \
    customer_manage.h \
    login_page.h \
    dialog.h \
    receipt_dilog.h \
    staff_manage.h \
    host_dialog.h

FORMS += \
    mainwindow.ui \
    customer_manage.ui \
    login_page.ui \
    dialog.ui \
    receipt_dilog.ui \
    staff_manage.ui \
    hostdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
