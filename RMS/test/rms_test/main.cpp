//#include "tst_unit_test.h"
#include "./test_domain/test_seatlist.h"
#include "./test_usecase/test_manage_order.h"
#include "./test_handler/test_handler.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
