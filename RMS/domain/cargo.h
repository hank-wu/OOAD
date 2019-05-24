#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo
{
public:
    Cargo(int id,std::string name,int amount);
    void increaseAmount(int amount);
    void decreaseAmount(int amount);
    int getAmount();
    std::string getName();
    int getId();

private:
    int _amount;
    std::string _name;
    int _id;
};

#endif // CARGO_H
