#ifndef ORDER_H
#define ORDER_H

#include <map>
#include "order_item.h"
#include "meal.h"
#include "seat.h"
#include "bill.h"
#include "receipt.h"
#include "order_pair.h"
#include <vector>

class Order
{
public:
    Order(Seat *seat);
    int orderCount();
    void add(Meal * meal , int quantity);
    int getAmount();
    void createBill();
    bool pay(int amount);
    int getBalance();
    Receipt * getReceipt();
    int getSeatId();
    std::vector<OrderPair> * getOrderPair();
    int getMealAmount(int id);

private:
    Seat *_seat;
    //OrderItem * _orderItem;
    std::map<int, OrderItem*> * _orderItemList;
    Bill * _bill = nullptr;
    bool _orderComplete;
};

#endif // ORDER_H
