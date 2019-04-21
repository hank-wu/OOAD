#include "seat_list.h"

SeatList::SeatList()
{

}

int SeatList::getCount(){
    return _count;
}

void SeatList::add(int id, Seat *seat){
    (*_seats)[id] = seat;
}

int SeatList::getNumberOfSeat(){
    return _seats->size();
}

void SeatList::clearSeat(int id){
    (*_seats)[id]->changeState();
}
