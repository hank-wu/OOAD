#include "seat.h"

Seat::Seat(int id,bool used): _id(id),_used(used)
{

}

int Seat::getId(){
    return _id;
}

bool Seat::isUsed(){
    return _used;
}
