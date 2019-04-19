include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_unit_test.h \
    test_domain/test_menu.h \
    test_usecase/test_manage_order.h \
    ../../usecase/manage_order.h \
    ../../domain/seat_list.h \
    test_usecase/test_show_seat_order.h \
    ../../domain/seat.h \
    ../../domain/meal.h   \
    ../../domain/meal_list.h   \


SOURCES += \
        main.cpp \
        ../../usecase/manage_order.cpp \
        ../../domain/seat_list.cpp  \
        ../../domain/seat.cpp   \
        ../../domain/meal.cpp   \
        ../../domain/meal_list.cpp   \
