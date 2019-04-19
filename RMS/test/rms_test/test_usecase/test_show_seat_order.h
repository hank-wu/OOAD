#ifndef TEST_SHOW_SEAT_ORDER_H
#define TEST_SHOW_SEAT_ORDER_H

#include "../../../usecase/manage_order.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


TEST(TestManageOrder, first)
{
    ManageOrder * m = new ManageOrder();
    ASSERT_EQ(10,m->getSeatCount());
}
#endif // TEST_SHOW_SEAT_ORDER_H
