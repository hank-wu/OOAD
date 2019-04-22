#include "seat_order.h"

SeatOrder::SeatOrder(int id,bool used) : Seat(id,used)
{

}

void SeatOrder::addOrderItem(Meal *meal, int quantity){
    if(!isUsed())
        changeState();

    std::map<int ,OrderItem *>::iterator it = _orderItemList->find(meal->getId());
    if( it != _orderItemList->end()){
        it->second->addQuantity(quantity);
    }
    else {
        (*_orderItemList)[meal->getId()] = new OrderItem(meal,quantity);
    }
}

std::map<int ,OrderItem *> * SeatOrder::getOrderItemList(){
    return _orderItemList;
}
