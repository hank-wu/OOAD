#ifndef SEAT_ORDER_H
#define SEAT_ORDER_H

#include "seat.h"
#include "order.h"

class SeatOrder
{
public:
    SeatOrder(Seat *seat);
    int getSeatId();
    void addOrderItem(Meal *, int);

private:
    Seat *_seat;
    Order *_order;
    OrderItem//meal number
    //std::map<Seat *,Order *> *_mapSeatOrder = new std::map<Seat *,Order *>();
};

#endif // SEAT_ORDER_H
