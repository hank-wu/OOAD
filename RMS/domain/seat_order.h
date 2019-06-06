#ifndef SEAT_ORDER_H
#define SEAT_ORDER_H

#include "seat.h"
#include "order_item.h"
#include "meal.h"
#include <map>

class SeatOrder : public Seat
{
public:
    SeatOrder(int,bool);
    void addOrderItem(Meal * meal, int quantity);
    std::map<int ,OrderItem *> * getOrderItemList();
    void clear();

private:
    std::map<int ,OrderItem *> *_orderItemList = new std::map<int ,OrderItem *>();
};

#endif // SEAT_ORDER_H
