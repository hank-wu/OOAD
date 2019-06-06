#include "order_item.h"

OrderItem::OrderItem(Meal *meal,int quantity): _meal(meal),_quantity(quantity)
{

}

Meal * OrderItem::getMeal(){
    return _meal;
}

int OrderItem::getQuantity(){
    return _quantity;
}

void OrderItem::addQuantity(int count){
    _quantity += count;
}

int OrderItem::subtotal(){
    return _quantity * _meal->getPrice();
}
