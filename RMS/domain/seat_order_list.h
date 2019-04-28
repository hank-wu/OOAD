#ifndef SEAT_ORDER_LIST_H
#define SEAT_ORDER_LIST_H

#include "seat_order.h"

class SeatOrderList
{
public:
    SeatOrderList();
    int getNumberOfSeatOrder();
    void addOrder(int seatId,Meal *meal,int quantity);
    std::map<int,SeatOrder *> * getAllSeatOrder();
    void clearSeat(int seatId);
    void refresh(std::map<int,Seat *> *seats);

private:
    const int _count = 10;
    std::map<int,SeatOrder *> *_seatOrders = new std::map<int,SeatOrder *>();
};

#endif // SEAT_ORDER_LIST_H
