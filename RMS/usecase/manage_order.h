#ifndef MANAGE_ORDER_H
#define MANAGE_ORDER_H

#include "../domain/seat_list.h"
#include "../domain/seat_order_list.h"

class ManageOrder
{
public:
    ManageOrder();
    ~ManageOrder();
    int getSeatCount();
    SeatOrderList * showSeatOrder();

private:
    SeatList * _seatList;
    SeatOrderList *_seatOrderList;
};

#endif // MANAGE_ORDER_H
