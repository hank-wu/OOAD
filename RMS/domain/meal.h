#ifndef MEAL_H
#define MEAL_H

#include <string>
using namespace std;

class Meal
{
public:
    Meal(string,string,int);
    string getName();
    string getDescription();
    int getPrice();

private:
    string _name;
    string _description;
    int _price;
};

#endif // MEAL_H
