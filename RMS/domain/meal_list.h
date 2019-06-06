#ifndef MEAL_LIST_H
#define MEAL_LIST_H

#include "meal.h"
#include <map>

class MealList
{
public:
    MealList();
    void add(int id,Meal *meal);
    int getNumberOfMeals();
    void set(std::map<int,Meal *> *MealList);

private:
    std::map<int,Meal *> *_mapMeal = new std::map<int,Meal *>();
};

#endif // MEAL_LIST_H
