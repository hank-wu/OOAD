#include "menu.h"

Menu::Menu()
{

}

int Menu::getNumberOfMeals(){
    return _mealList->size();
}

void Menu::refresh(std::map<int, Meal *> *MealList){
    for(std::map<int,Meal *>::iterator it = _mealList->begin();it != _mealList->end();it++){
        delete it->second;
    }
    _mealList->clear();

    for(std::map<int,Meal *>::iterator it = MealList->begin();it != MealList->end();it++){
        (*_mealList)[it->first] = it->second;
    }
}

std::map<int,Meal *> * Menu::getMenu(){
    return _mealList;
}

Meal * Menu::getMeal(int id){
    return (*_mealList)[id];
}
