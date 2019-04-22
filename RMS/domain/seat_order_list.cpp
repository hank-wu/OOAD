#include "seat_order_list.h"

SeatOrderList::SeatOrderList()
{
    for(int i=1;i<=_count;i++)
        (*_seatOrders)[i] = new SeatOrder(i,false);
}

int SeatOrderList::getNumberOfSeatOrder(){
    return _seatOrders->size();
}

void SeatOrderList::addOrder(int seatId, Meal *meal, int quantity){
    (*_seatOrders)[seatId]->addOrderItem(meal,quantity);
}

std::map<int,SeatOrder *> * SeatOrderList::getAllSeatOrder(){
    return _seatOrders;
}

void SeatOrderList::clearSeat(int seatId){
    (*_seatOrders)[seatId]->clear();
}
