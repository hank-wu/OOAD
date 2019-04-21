#include "seat_list.h"

SeatList::SeatList()
{

}

void SeatList::refreshList(std::map<int, Seat> * seats){
    _seats = seats;
}

int SeatList::getCount(){
    return _count;
}
