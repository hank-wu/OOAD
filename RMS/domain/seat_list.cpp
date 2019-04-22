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

void SeatList::clearSeat(int id){
    (*_seats)[id]->changeState();
}

void SeatList::refresh(int id, Seat *seat){
    if((*_seats)[id]->isUsed() != seat->isUsed())
        (*_seats)[id]->changeState();
}

void SeatList::refresh(std::map<int, Seat *> *seats){
    for(std::map<int,Seat *>::iterator it= _seats->begin();it != _seats->end(); ++it){
        int id = it->first;
        if(it->second->isUsed() != (*seats)[id]->isUsed())
            it->second->changeState();
    }
}
