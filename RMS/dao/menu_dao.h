#ifndef MENU_DAO_H
#define MENU_DAO_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <string>
#include "../domain/meal.h"
#include <map>
using std::string;

class MenuDao
{
public:
    MenuDao(QSqlQuery * query, QSqlDatabase * mydb);
    std::map<int,Meal *> * getMealList();
    void closeDB();
    bool createMeal(QString name,QString description,int price);
    bool editMeal(int id,QString name,QString description,int price);
    bool deleteMeal(int id);

private:
    string _path;
    QSqlQuery * _query;
    QSqlDatabase * _mydb;
};

#endif // MENU_DAO_H
