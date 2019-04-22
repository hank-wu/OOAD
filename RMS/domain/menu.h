#ifndef MENU_H
#define MENU_H

#include "meal.h"
#include <map>

class Menu
{
public:
    Menu();
    void add(int id,Meal *meal);
    int getNumberOfMeals();
    void refresh(std::map<int,Meal *> *MealList);
    std::map<int,Meal *> * getMenu();

private:
    std::map<int,Meal *> *_mapMeal = new std::map<int,Meal *>();
};

#endif // MENU_H
