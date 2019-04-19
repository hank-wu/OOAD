#ifndef TEST_MANAGE_ORDER_H
#define TEST_MANAGE_ORDER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../usecase/manage_order.h"


TEST(TestManageOrder, first)
{
    ManageOrder * m = new ManageOrder();
    ASSERT_EQ(10,m->getSeatCount());
}

#endif // TEST_MANAGE_ORDER_H
