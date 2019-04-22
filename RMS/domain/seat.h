#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat
{
public:
    Seat(int,bool);
    Seat(int,bool,std::string);
    bool isUsed();
    int getSeatId();
    void changeState();
    void setTableName(std::string tableName);
    std::string getTableName();

private:
    bool _used;
    int _id;
    std::string _tableName;
};

#endif // SEAT_H
