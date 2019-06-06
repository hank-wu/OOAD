#include "warehouse.h"
#include <QDebug>
#include <iostream>

Warehouse::Warehouse()
{
    _cargoList = new std::map<int,Cargo *>();
}

void Warehouse::buildCargo(Cargo * cargo){
    (*_cargoList)[cargo->getId()] = cargo;
}

bool Warehouse::increaseCargoAmount(int id, int amount){
    int totalCapacity = 0;
    for(std::map<int,Cargo *>::iterator it = _cargoList->begin();it != _cargoList->end(); it++){
        totalCapacity += it->second->getAmount();
    }
    if(totalCapacity+amount > _capacity)
        return false;
    Cargo * cargo = (*_cargoList)[id];
    cargo->increaseAmount(amount);
    return true;
}

bool Warehouse::decreaseCargoAmount(int id, int amount){
    Cargo * cargo = (*_cargoList)[id];
    if(cargo->getAmount() < amount)
        return false;
    cargo->decreaseAmount(amount);
    return true;
}

int Warehouse::getCargoAmount(int id){
    Cargo * cargo = (*_cargoList)[id];
    return cargo->getAmount();
}

void Warehouse::buildCargoList(std::map<int, Cargo *> *cargoList){
//    std::cout<<"AAA001"<<std::endl;
//    for(std::map<int, Cargo *>::iterator it = cargoList->begin(); it != cargoList->end(); it++){
//        std::cout<<" cargoName = "<<it->second->getName()<<std::endl;
//    }
    _cargoList = cargoList;
}

std::map<int, Cargo *> * Warehouse::getCargoList(){
    return _cargoList;
}

