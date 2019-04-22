#include "seat_order_list.h"

SeatOrderList::SeatOrderList()
{
    for(int i=1;i<=_count;i++)
        (*_seatOrderList)[i] = new SeatOrder(i,false);
}

int SeatOrderList::getNumberOfSeatOrder(){
    return _seatOrderList->size();
}

void SeatOrderList::addOrder(int seatId, Meal *meal, int quantity){
    (*_seatOrderList)[seatId]->addOrderItem(meal,quantity);
}

std::map<int,SeatOrder *> * SeatOrderList::getSeatOrderList(){
    return _seatOrderList;
}
