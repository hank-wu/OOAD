#include "cargo.h"

Cargo::Cargo(int id,std::string name,int amount): _id(id),_name(name),_amount(amount)
{

}

void Cargo::increaseAmount(int amount){
    _amount += amount;
}

void Cargo::decreaseAmount(int amount){
    _amount -= amount;
}

int Cargo::getAmount(){
    return _amount;
}

std::string Cargo::getName(){
    return _name;
}

int Cargo::getId(){
    return _id;
}
