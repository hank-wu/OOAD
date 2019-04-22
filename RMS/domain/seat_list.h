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
    //void clearSeat(int id);
    void refresh(std::map<int,Seat *> *seats);
    void refresh(int id, Seat *seat);
    void getSeat(int id);

private:
    const int _count = 10;
    std::map<int,Seat *> * _seats = new std::map<int,Seat *>();
};

#endif // SEAT_LIST_H
