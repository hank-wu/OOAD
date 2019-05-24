#ifndef TEST_CARGO_H
#define TEST_CARGO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../domain/cargo.h"
using namespace testing;

TEST(TestCargo, increaseAmount)
{
    Cargo * riceCargo = new Cargo(1,"三寶飯貨物",10);
    riceCargo->increaseAmount(5);
    ASSERT_EQ(15,riceCargo->getAmount());
}

#endif // TEST_CARGO_H
