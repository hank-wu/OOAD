#include "seat.h"

Seat::Seat(int id,bool used): _id(id),_used(used)
{

}

bool Seat::isUsed(){
    return _used;
}

int Seat::getSeatId(){
    return _id;
}

void Seat::changeState(){
    _used = !_used;
}
