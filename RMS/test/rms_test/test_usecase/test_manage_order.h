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
#include "../../../domain/menu.h"
#include "../../../domain/order_item.h"
#include "../../../domain/bill.h"
#include "../../../domain/receipt.h"

#include <map>

TEST(TestManageOrder, getSeatCount)
{
    ManageOrder * m = new ManageOrder();
    ASSERT_EQ(10,m->getSeatCount());
}

TEST(TestSeat,getSeatId)
{
    Seat * seat_one = new Seat(1,true);
    ASSERT_EQ(1,seat_one->getSeatId());
}

TEST(TestMeal,getName)
{
    Meal * meal_one = new Meal(1,"apple","good",10);
    ASSERT_EQ("apple",meal_one->getName());//test Meal

}

TEST(TestMenu,getMeal)
{
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    (*mealList)[1] = meal_one;
    (*mealList)[2] = meal_two;

    Menu * menu = new Menu();
    menu->refresh(mealList);
    ASSERT_EQ(meal_two,menu->getMeal(2));

}

TEST(TestOrderItem,getMeal)
{
    Meal * meal_one = new Meal(1,"apple","good",10);
    OrderItem * orderItem = new OrderItem(meal_one,5);
    ASSERT_EQ(meal_one,orderItem->getMeal());
    ASSERT_EQ(5,orderItem->getQuantity());

    orderItem->addQuantity(3);
    ASSERT_EQ(8,orderItem->getQuantity());
}

TEST(TestSeat,02)
{
    Seat * seat_one = new Seat(1,true);
    ASSERT_EQ(1,seat_one->getSeatId());
}

TEST(TestSeatOrder,03)
{
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    SeatOrder * seatOrder = new SeatOrder(1,false);
    seatOrder->addOrderItem(meal_one,5);
    seatOrder->addOrderItem(meal_one,3);
    seatOrder->addOrderItem(meal_two,6);

    std::map<int ,OrderItem *> *_orderItemList;
    _orderItemList = seatOrder->getOrderItemList();

    ASSERT_EQ(meal_one,(*_orderItemList)[1]->getMeal());
    ASSERT_EQ(8,(*_orderItemList)[1]->getQuantity());

}

TEST(TestSeatOrderList,04)
{
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);

    SeatOrderList * seatOrderList = new SeatOrderList();
    seatOrderList->addOrder(1,meal_one,8);
    seatOrderList->addOrder(1,meal_two,6);

    std::map<int,SeatOrder *> *seatOrderList_one;
    seatOrderList_one = seatOrderList->getAllSeatOrder();

    ASSERT_EQ(true,(*seatOrderList_one)[1]->isUsed());
    SeatOrder *seatOrder_one = (*seatOrderList_one)[1];
    std::map<int ,OrderItem *> *orderItemList;
    orderItemList = seatOrder_one->getOrderItemList();
    ASSERT_EQ(8,(*orderItemList)[1]->getQuantity());

}

TEST(TestSeatOrderClear,05)
{
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    SeatOrderList * seatOrderList = new SeatOrderList();
    seatOrderList->addOrder(1,meal_one,8);
    seatOrderList->addOrder(1,meal_two,6);

    std::map<int,SeatOrder *> *seatOrderList_one;
    seatOrderList_one = seatOrderList->getAllSeatOrder();
    ASSERT_EQ(true,(*seatOrderList_one)[1]->isUsed());
    seatOrderList->clearSeat(1);
    ASSERT_EQ(false,(*seatOrderList_one)[1]->isUsed());

}

TEST(TestSeatListTableName,06)
{
    SeatList *seatList = new SeatList();
    std::map<int,Seat *> * seats = new std::map<int,Seat *>();
    Seat * seat_one = new Seat(1,true,std::string("A1"));
    Seat * seat_two = new Seat(2,true,std::string("A2"));
    (*seats)[1] = seat_one;
    (*seats)[2] = seat_two;
    seatList->refresh(seats);

    std::map<int,Seat *> * seatsAns;
    seatsAns = seatList->getAllSeats();
    ASSERT_EQ(true,(*seatsAns)[1]->isUsed());
    ASSERT_EQ(std::string("A1"),(*seatsAns)[1]->getTableName());
    ASSERT_EQ(true,(*seatsAns)[2]->isUsed());
    ASSERT_EQ(std::string("A2"),(*seatsAns)[2]->getTableName());
}

TEST(TestOrder, 01)
{
    Seat * seat_one = new Seat(1,true,std::string("A1"));
    Order * order = new Order(seat_one);
    ASSERT_EQ(0,order->orderCount());
    Meal * meal_one = new Meal(1,"apple","good",10);
    order->add(meal_one,20);
    ASSERT_EQ(20,order->orderCount());
    ASSERT_EQ(200, order->getAmount());
}

TEST(TestBill,099)
{
    Bill * bill = new Bill(1000);
    bill->pay(1500);
    ASSERT_EQ(500,bill->getBalance());
}

TEST(TestOrderPay,098)
{
    Seat * seat_one = new Seat(1,true,std::string("A1"));
    Order * order = new Order(seat_one);
    ASSERT_EQ(0,order->orderCount());
    Meal * meal_one = new Meal(1,"apple","good",10);
    order->add(meal_one,20);
    ASSERT_EQ(20,order->orderCount());
    ASSERT_EQ(200, order->getAmount());

    order->createBill();
    ASSERT_EQ(true,order->pay(230));
    ASSERT_EQ(30,order->getBalance());

}

TEST(TestOrderReceipt,097)
{
    Seat * seat_one = new Seat(1,true,std::string("A1"));
    Order * order = new Order(seat_one);
    ASSERT_EQ(0,order->orderCount());
    Meal * meal_one = new Meal(1,"apple","good",10);
    order->add(meal_one,20);
    ASSERT_EQ(20,order->orderCount());
    ASSERT_EQ(200, order->getAmount());

    order->createBill();
    ASSERT_EQ(true,order->pay(230));
    ASSERT_EQ(30,order->getBalance());

    Receipt * receipt = order->getReceipt();
    ASSERT_EQ("apple  200\n",receipt->content());
}

TEST(TestReceipt,096)
{
    Receipt * receipt = new Receipt("A1");
    receipt->setItem("apple",200);
    receipt->setItem("banana",125);
    ASSERT_EQ("apple  200\nbanana  125\n",receipt->content());
}

/*
TEST(TestShowSeatOrder, first)
{

    MealList * mealList_one = new MealList();
    Menu * menu = new
    Meal * meal_one = new Meal("apple","good",10);
    ASSERT_EQ("apple",meal_one->getName());//test Meal

    mealList_one->add(1,meal_one);
    Meal * meal_two = new Meal("banana","yellow",20);
    mealList_one->add(2,meal_two);
    ASSERT_EQ(2,mealList_one->getNumberOfMeals());//test MealList

    Order * order_one = new Order(115,mealList_one);
    ASSERT_EQ(2,order_one->getNumberOfMeals());//test Order

    SeatOrder * seatOrder_one = new SeatOrder(seat_one,order_one);
    ASSERT_EQ(1,seatOrder_one->getSeatId());

    SeatOrderList * seatOrderList = new SeatOrderList();
    seatOrderList->add(17,seatOrder_one);
    ASSERT_EQ(1,seatOrderList->getNumberOfSeatOrder());

}

TEST(TestClearSeat, first)
{

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
}*/

#endif // TEST_MANAGE_ORDER_H
