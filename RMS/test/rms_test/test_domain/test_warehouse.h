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
    bool result;
    result = warehouse->increaseCargoAmount(1,5);
    ASSERT_EQ(true,result);
    ASSERT_EQ(15,riceCargo->getAmount());

    result = warehouse->increaseCargoAmount(1,200);
    ASSERT_EQ(false,result);

}

TEST(TestWarehouse, decreaseAmount)
{
    Warehouse * warehouse = new Warehouse();
    Cargo * riceCargo = new Cargo(1,"三寶飯貨物",10);
    warehouse->buildCargo(riceCargo);
    bool result;
    result = warehouse->decreaseCargoAmount(1,5);
    ASSERT_EQ(true,result);
    ASSERT_EQ(5,riceCargo->getAmount());

    result = warehouse->decreaseCargoAmount(1,10);
    ASSERT_EQ(false,result);
}

TEST(TestWarehouse, getCargoAmount)
{
    Warehouse * warehouse = new Warehouse();
    Cargo * riceCargo = new Cargo(1,"三寶飯貨物",10);
    warehouse->buildCargo(riceCargo);
    int amount = warehouse->getCargoAmount(1);
    ASSERT_EQ(10,amount);
}


#endif // TEST_WAREHOUSE_H
