#include "seat_order_list.h"

SeatOrderList::SeatOrderList()
{

}

void SeatOrderList::add(int id, SeatOrder *seatOrder){
    (*_mapSeatOrderList)[id] = seatOrder;
}

int SeatOrderList::getNumberOfSeatOrder(){
    return _mapSeatOrderList->size();
}
