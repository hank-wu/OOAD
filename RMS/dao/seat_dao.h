#ifndef SEAT_DAO_H
#define SEAT_DAO_H

#include <QString>
#include <string>
#include "../domain/seat.h"
#include <map>
using std::string;

class SeatDao
{
public:
    SeatDao(string path);
    string getPath();
    std::map<int,Seat *> * getSeatList();
    Seat * getSeat(int inputId);
private:
    string _path;

};

#endif // SEAT_DAO_H
