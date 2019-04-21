#ifndef TEST_HANDLER_H
#define TEST_HANDLER_H

#include "../../../handler.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(TestHandler, first)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TEST_HANDLER_H
