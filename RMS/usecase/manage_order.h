#ifndef MANAGE_ORDER_H
#define MANAGE_ORDER_H

#include "../domain/seat_list.h"

class ManageOrder
{
public:
    ManageOrder();
    ~ManageOrder();
    int getSeatCount();

private:
    SeatList * _seatList;
};

#endif // MANAGE_ORDER_H
