#ifndef SEAT_LIST_H
#define SEAT_LIST_H

#include <map>
#include "seat.h"

class SeatList
{
public:
    SeatList();
    int getCount();
    int getNumberOfSeat();
    void refresh(std::map<int,Seat *> *seats);
    void refresh(int id, Seat *seat);
    std::map<int,Seat *> * getAllSeats();

private:
    const int _count = 10;
    std::map<int,Seat *> * _seats = new std::map<int,Seat *>();
};

#endif // SEAT_LIST_H
