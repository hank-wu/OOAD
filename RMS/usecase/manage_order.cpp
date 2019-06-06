#include "manage_order.h"

ManageOrder::ManageOrder()
{
    _seatList = new SeatList();
}

ManageOrder::~ManageOrder()
{
    delete _seatList;
}

int ManageOrder::getSeatCount(){
    return _seatList->getCount();
}

SeatOrderList * ManageOrder::showSeatOrder(){
    return _seatOrderList;
}

