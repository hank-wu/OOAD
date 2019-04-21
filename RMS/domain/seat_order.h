#ifndef SEAT_ORDER_H
#define SEAT_ORDER_H

#include "seat.h"
#include "order.h"

class SeatOrder
{
public:
    SeatOrder(Seat *seat,Order *order);
    int getSeatId();

private:
    Seat *_seat;
    Order *_order;
    //std::map<Seat *,Order *> *_mapSeatOrder = new std::map<Seat *,Order *>();
};

#endif // SEAT_ORDER_H
