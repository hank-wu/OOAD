#ifndef SEAT_LIST_H
#define SEAT_LIST_H

#include <map>
#include "seat.h"

class SeatList
{
public:
    SeatList();
    void refreshList(std::map<int, Seat> *);
    std::map<int, Seat> * getList();
    int getCount();

private:
    const int _count = 10;
    std::map<int,Seat> * _seats;
};

#endif // SEAT_LIST_H
