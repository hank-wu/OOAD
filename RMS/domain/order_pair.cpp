#include "order_pair.h"

OrderPair::OrderPair(int id,int amount): _id(id), _amount(amount)
{

}

int OrderPair::getId(){
    return _id;
}

int OrderPair::getAmount(){
    return _amount;
}
