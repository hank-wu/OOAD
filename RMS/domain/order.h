#ifndef ORDER_H
#define ORDER_H

#include "meal_list.h"

class Order
{
public:
    Order(int id,MealList *mealList);
    int getNumberOfMeals();

private:
    int _id;
    MealList *_mealList;
};

#endif // ORDER_H
