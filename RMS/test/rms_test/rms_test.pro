include(gtest_dependency.pri)

QT  += core \
        sql \
        network \
        gui \
        widgets \

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

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
        ../../domain/order.h   \
        ../../domain/seat_order.h   \
        ../../domain/seat_order_list.h   \
        ../../domain/menu.h   \
        ../../domain/order_item.h   \
        ../../domain/bill.h   \
        ../../domain/receipt.h   \
        ../../dao/menu_dao.h   \
        test_dao/test_menu_dao.h    \
        ../../dao/seat_dao.h   \
        test_dao/test_seat_dao.h \
    test_controller/test_rms_handler.h  \
        ../../domain/order_pair.h   \
        ../../rmshandler.h   \
        ../../socket.h   \
        ../../domain/cargo.h   \
    test_domain/test_cargo.h    \
        ../../dao/cargo_dao.h   \
    test_domain/test_warehouse.h    \
        ../../domain/warehouse.h   \
    test_dao/test_cargo_dao.h


SOURCES += \
        main.cpp \
        ../../usecase/manage_order.cpp \
        ../../domain/seat_list.cpp  \
        ../../domain/seat.cpp   \
        ../../domain/meal.cpp   \
        ../../domain/meal_list.cpp   \
        ../../domain/order.cpp   \
        ../../domain/seat_order.cpp   \
        ../../domain/seat_order_list.cpp   \
        ../../domain/menu.cpp   \
        ../../domain/order_item.cpp   \
        ../../domain/bill.cpp   \
        ../../domain/receipt.cpp   \
        ../../dao/menu_dao.cpp   \
        ../../dao/seat_dao.cpp   \
        ../../domain/order_pair.cpp   \
        ../../rmshandler.cpp   \
        ../../socket.cpp   \
        ../../domain/cargo.cpp   \
        ../../dao/cargo_dao.cpp   \
        ../../domain/warehouse.cpp   \

