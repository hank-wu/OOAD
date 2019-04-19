#ifndef TEST_MANAGE_ORDER_H
#define TEST_MANAGE_ORDER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../usecase/manage_order.h"
#include "../../../domain/seat.h"
#include "../../../domain/meal.h"
#include "../../../domain/meal_list.h"


#include <map>

TEST(TestManageOrder, first)
{
    ManageOrder * m = new ManageOrder();
    ASSERT_EQ(10,m->getSeatCount());
}

TEST(TestShowSeatOrder, first)
{
    ManageOrder * m = new ManageOrder();
    //SeatOrderList * sol = new SeatOrderList();

    Seat * seat_one = new Seat(1,true);
    MealList * ml_one = new MealList();
    Meal * meal_one = new Meal("apple","good",10);
    ml_one->add(1,meal_one);
    Meal * meal_two = new Meal("banana","yellow",20);
    ml_one->add(2,meal_two);
    Order * order_one = new Order(115,ml_one);
    SeatOrder * seatOrder_one = new SeatOrder(seat_one,order_one);

    std::map<int,SeatOrder> * mapSeatOrder;
    mapSeatOrder[1] = seatOrder_one;

    ASSERT_EQ("apple",meal_one->getName());//test Meal
    ASSERT_EQ(2,ml_one->getNumberOfMeals());//test MealList
    ASSERT_EQ(2,order_one->getNumberOfMeals());//test Order

    //ASSERT_EQ(10,m->getSeatCount());
}

#endif // TEST_MANAGE_ORDER_H
