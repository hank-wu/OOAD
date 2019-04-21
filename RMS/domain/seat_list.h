#ifndef SEAT_LIST_H
#define SEAT_LIST_H

#include <map>
#include "seat.h"

class SeatList
{
public:
    SeatList();
    int getCount();
    void add(int id,Seat *seat);
    int getNumberOfSeat();
    void clearSeat(int id);

private:
    const int _count = 10;
    std::map<int,Seat *> * _seats = new std::map<int,Seat *>();
};

#endif // SEAT_LIST_H
