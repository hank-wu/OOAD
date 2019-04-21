#ifndef SEAT_ORDER_LIST_H
#define SEAT_ORDER_LIST_H

#include "seat_order.h"

class SeatOrderList
{
public:
    SeatOrderList();
    void add(int id,SeatOrder *seatOrder);
    int getNumberOfSeatOrder();

private:
    std::map<int,SeatOrder *> *_mapSeatOrderList = new std::map<int,SeatOrder *>();
};

#endif // SEAT_ORDER_LIST_H
