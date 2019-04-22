#include "meal.h"

Meal::Meal(int id,string name,string description,int price):
    _id(id),_name(name),_description(description),_price(price)
{

}

string Meal::getName(){
    return _name;
}

string Meal::getDescription(){
    return _description;
}

int Meal::getPrice(){
    return _price;
}

int Meal::getId(){
    return _id;
}
