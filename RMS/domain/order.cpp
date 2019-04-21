#include "order.h"

Order::Order(int id,MealList *mealList): _id(id),_mealList(mealList)
{

}

int Order::getNumberOfMeals(){
    return _mealList->getNumberOfMeals();
}
