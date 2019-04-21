include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_unit_test.h \
    test_usecase/test_manage_order.h \
    ../../usecase/manage_order.h \
    ../../domain/seat_list.h \
    test_handler/test_handler.h \
    ../../handler.h \
    ../../domain/seat.h \
    test_domain/test_seatlist.h

SOURCES += \
        main.cpp \
        ../../usecase/manage_order.cpp \
        ../../domain/seat_list.cpp \
        ../../handler.cpp \
        ../../domain/seat.cpp
