#ifndef SEAT_ORDER_LIST_H
#define SEAT_ORDER_LIST_H

#include "seat_order.h"

class SeatOrderList
{
public:
    SeatOrderList();
    int getNumberOfSeatOrder();
    void addOrder(int seatId,Meal *meal,int quantity);
    std::map<int,SeatOrder *> * getSeatOrderList();

private:
    const int _count = 10;
    std::map<int,SeatOrder *> *_seatOrderList = new std::map<int,SeatOrder *>();
};

#endif // SEAT_ORDER_LIST_H
