#include "meal_list.h"

MealList::MealList()
{
}

void MealList::add(int id, Meal *meal){
    //_mapMeal->insert(std::pair<int,Meal *>(id,meal));
    (*_mapMeal)[id] = meal;
}

int MealList::getNumberOfMeals(){
    return _mapMeal->size();
}
