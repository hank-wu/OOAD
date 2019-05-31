#include "boss_handler.h"

BossHandler::BossHandler(MenuDao * menuDao): _menuDao(menuDao)
{
    _menu = new Menu();
}

void BossHandler::refreshMenu(){
    std::map<int,Meal *> * mealList = _menuDao->getMealList();
    _menu->refresh(mealList);
}

std::map<int,Meal *> *  BossHandler::showMenu(){
    return  _menu->getMenu();
}

bool BossHandler::createMeal(QString name, QString description, int price){
    if(name.size() == 0)
        return false;
    if(!_menuDao->createMeal(name,description,price))
        return false;
    _menu->createMeal(std::string((const char *)name.toLocal8Bit()),std::string((const char *)description.toLocal8Bit()),price);
    return true;
}

bool BossHandler::editMeal(int id, QString name, QString description, int price){
    if(name.size() == 0)
        return false;
    if(!_menuDao->editMeal(id,name,description,price))
        return false;
    _menu->editMeal(id,std::string((const char *)name.toLocal8Bit()),std::string((const char *)description.toLocal8Bit()),price);
    return true;
}

bool BossHandler::deleteMeal(int id){
    if(!_menuDao->deleteMeal(id))
        return false;
    _menu->deleteMeal(id);
    return true;
}
