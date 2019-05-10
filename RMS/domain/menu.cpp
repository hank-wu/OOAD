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

void Menu::createMeal(std::string name, std::string description, int price){
    int newId;
    if(_mealList->size()>0){
        std::map<int,Meal *>::iterator it = _mealList->end();
        it--;
        newId = it->first+1;
    }
    else {
        newId = 1;
    }

    Meal * newMeal = new Meal(newId,name,description,price);
    (*_mealList)[newId] = newMeal;

}

void Menu::editMeal(int id, std::string name, std::string description, int price){
    Meal * editMeal;
    editMeal = (*_mealList)[id];
    editMeal->setName(name);
    editMeal->setDescription(description);
    editMeal->setPrice(price);
}

void Menu::deleteMeal(int id){
    delete (*_mealList)[id];
    _mealList->erase(id);
}
