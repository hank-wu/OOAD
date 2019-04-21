#ifndef SEAT_H
#define SEAT_H

class Seat
{
public:
    Seat(int,bool);
    int getId();
    bool isUsed();
private:
    bool _used = true;
    int _id = 123;
};

#endif // SEAT_H
