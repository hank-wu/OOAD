#ifndef MENU_DAO_H
#define MENU_DAO_H

#include <QString>
#include <string>
#include "../domain/meal.h"
#include <map>
using std::string;

class MenuDao
{
public:
    MenuDao(string path);
    string getPath();
    std::map<int,Meal *> * getMealList();


private:
    string _path;
};

#endif // MENU_DAO_H
