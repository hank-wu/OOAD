#ifndef TEST_WAREHOUSE_H
#define TEST_WAREHOUSE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../domain/warehouse.h"
#include "../../../domain/cargo.h"
using namespace testing;

TEST(TestWarehouse, increaseAmount)
{
    Warehouse * warehouse = new Warehouse();
    Cargo * riceCargo = new Cargo(1,"三寶飯貨物",10);
    warehouse->buildCargo(riceCargo);
    warehouse->increaseCargoAmount(1,5);
    ASSERT_EQ(15,riceCargo->getAmount());
}

#endif // TEST_WAREHOUSE_H
