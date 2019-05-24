#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "./cargo.h"
#include <map>
class Warehouse
{
public:
    Warehouse();
    void buildCargo(Cargo * cargo);
    void increaseCargoAmount(int id,int amount);
    void decreaseCargoAmount(int id,int amount);

private:
    int _capacity = 200;
    std::map<int,Cargo *> * _cargoList;
};

#endif // WAREHOUSE_H
