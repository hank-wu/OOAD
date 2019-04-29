
#include "./test_domain/test_menu.h"
#include "./test_usecase/test_manage_order.h"
#include "./test_dao/test_menu_dao.h"
#include "./test_dao/test_seat_dao.h"
#include "./test_controller/test_rms_handler.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
