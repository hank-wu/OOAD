#ifndef SEAT_H
#define SEAT_H

class Seat
{
public:
    Seat(int,bool);
    bool isUsed();
    int getSeatId();
private:
    bool _used;
    int _id;
};

#endif // SEAT_H
