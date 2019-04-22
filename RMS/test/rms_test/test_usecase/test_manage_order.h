#ifndef TEST_MANAGE_ORDER_H
#define TEST_MANAGE_ORDER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../usecase/manage_order.h"
#include "../../../domain/seat.h"
#include "../../../domain/seat_list.h"
#include "../../../domain/meal.h"
#include "../../../domain/meal_list.h"
#include "../../../domain/order.h"
#include "../../../domain/seat_order.h"
#include "../../../domain/seat_order_list.h"

#include <map>

TEST(TestManageOrder, first)
{
    ManageOrder * m = new ManageOrder();
    ASSERT_EQ(10,m->getSeatCount());
}

TEST(TestShowSeatOrder, first)
{
    //ManageOrder * m = new ManageOrder();

    Seat * seat_one = new Seat(1,true);
    ASSERT_EQ(1,seat_one->getSeatId());

    MealList * mealList_one = new MealList();
    Meal * meal_one = new Meal("apple","good",10);
    ASSERT_EQ("apple",meal_one->getName());//test Meal

    mealList_one->add(1,meal_one);
    Meal * meal_two = new Meal("banana","yellow",20);
    mealList_one->add(2,meal_two);
    ASSERT_EQ(2,mealList_one->getNumberOfMeals());//test MealList

    Order * order_one = new Order(115,mealList_one);
    ASSERT_EQ(2,order_one->getNumberOfMeals());//test Order

    /*SeatOrder * seatOrder_one = new SeatOrder(seat_one,order_one);
    ASSERT_EQ(1,seatOrder_one->getSeatId());

    SeatOrderList * seatOrderList = new SeatOrderList();
    seatOrderList->add(17,seatOrder_one);
    ASSERT_EQ(1,seatOrderList->getNumberOfSeatOrder());*/

}

TEST(TestClearSeat, first)
{
    Seat * seat_one = new Seat(1,true);
    ASSERT_EQ(1,seat_one->getSeatId());
    Seat * seat_two = new Seat(7,true);

    seat_one->changeState();
    ASSERT_EQ(false,seat_one->isUsed());

    SeatList *seatList = new SeatList();
    seatList->add(1,seat_one);
    seatList->add(7,seat_two);
    ASSERT_EQ(2,seatList->getNumberOfSeat());

    ASSERT_EQ(true,seat_two->isUsed());
    seatList->clearSeat(7);
    ASSERT_EQ(false,seat_two->isUsed());
}

#endif // TEST_MANAGE_ORDER_H
