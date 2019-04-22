#include "seat.h"

Seat::Seat(int id,bool used): _id(id),_used(used)
{

}

Seat::Seat(int id,bool used,std::string tableName): _id(id),_used(used), _tableName(tableName)
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

void Seat::setTableName(std::string tableName){
    _tableName = tableName;
}

std::string Seat::getTableName(){
    return _tableName;
}
