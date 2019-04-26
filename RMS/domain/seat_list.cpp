#include "seat_list.h"

SeatList::SeatList()
{
    for(int i=1;i<=_count;i++)
        (*_seats)[i] = new Seat(i,false);
}

int SeatList::getCount(){
    return _count;
}

int SeatList::getNumberOfSeat(){
    return _seats->size();
}

void SeatList::refresh(int id, Seat *seat){
    if((*_seats)[id]->isUsed() != seat->isUsed())
        (*_seats)[id]->changeState();
}

void SeatList::refresh(std::map<int, Seat *> *seats){
    for(std::map<int,Seat *>::iterator it= seats->begin();it != seats->end(); ++it){
        int id = it->first;
        (*_seats)[id]->setTableName(it->second->getTableName());
        if(it->second->isUsed() != (*_seats)[id]->isUsed())
            (*_seats)[id]->changeState();
    }
}

std::map<int,Seat *> * SeatList::getAllSeats(){
    return _seats;
}

Seat * SeatList::getSeat(int seatId){
    return (*_seats)[seatId];
}
