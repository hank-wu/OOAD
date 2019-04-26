#ifndef MENU_DAO_H
#define MENU_DAO_H

#include <QString>
#include <QSqlQuery>
#include <string>
#include "../domain/meal.h"
#include <map>
using std::string;

class MenuDao
{
public:
    MenuDao(QSqlQuery * query);
    std::map<int,Meal *> * getMealList();


private:
    string _path;
    QSqlQuery * _query;
};

#endif // MENU_DAO_H
