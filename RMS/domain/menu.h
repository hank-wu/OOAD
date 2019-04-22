#ifndef MENU_H
#define MENU_H

#include "meal.h"
#include <map>

class Menu
{
public:
    Menu();
    int getNumberOfMeals();
    void refresh(std::map<int,Meal *> *MealList);
    std::map<int,Meal *> * getMenu();
    Meal * getMeal(int id);

private:
    std::map<int,Meal *> *_mealList = new std::map<int,Meal *>();
};

#endif // MENU_H
