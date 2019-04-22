#ifndef ORDER_H
#define ORDER_H

#include "order_item.h"
#include "seat.h"

class Order
{
public:
    Order(Seat *seat);
    int getNumberOfMeals();

private:
    Seat *_seat;
    OrderItem * _orderItem;
};

#endif // ORDER_H
