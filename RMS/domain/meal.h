#ifndef MEAL_H
#define MEAL_H

#include <string>
using namespace std;

class Meal
{
public:
    Meal(int,string,string,int);
    string getName();
    string getDescription();
    int getPrice();
    int getId();
    void setName(string name);
    void setDescription(string description);
    void setPrice(int price);

private:
    int _id;
    string _name;
    string _description;
    int _price;

};

#endif // MEAL_H
