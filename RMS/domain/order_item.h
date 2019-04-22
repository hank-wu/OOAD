#ifndef ORDER_ITEM_H
#define ORDER_ITEM_H

#include "meal.h"

class OrderItem
{
public:
    OrderItem(Meal *meal,int quantity);
    Meal * getMeal();
    int getQuantity();
    void addQuantity(int count);

private:
    Meal * _meal;
    int _quantity;
};

#endif // ORDER_ITEM_H
