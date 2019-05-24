#include "warehouse.h"

Warehouse::Warehouse()
{
    _cargoList = new std::map<int,Cargo *>();
}

void Warehouse::buildCargo(Cargo * cargo){
    (*_cargoList)[cargo->getId()] = cargo;
}

void Warehouse::increaseCargoAmount(int id, int amount){
    Cargo * cargo = (*_cargoList)[id];
    cargo->increaseAmount(amount);
}

void Warehouse::decreaseCargoAmount(int id, int amount){
    Cargo * cargo = (*_cargoList)[id];
    cargo->decreaseAmount(amount);
}
