#include "menu_dao.h"
#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>
using std::string;

MenuDao::MenuDao(QSqlQuery * query): _query(query)
{

}

std::map<int,Meal *> * MenuDao::getMealList(){
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();

    _query->exec("select * from menu");

    while(_query->next())
    {
        int rowNum = _query->at();
        //int columnNum = _query->record().count();
        int fieldId = _query->record().indexOf("id");
        int fieldName = _query->record().indexOf("name");
        int fieldDescription = _query->record().indexOf("description");
        int fieldPrice = _query->record().indexOf("price");


        int id = _query->value(fieldId).toInt();
        int price = _query->value(fieldPrice).toInt();
        QString qstrName = _query->value(fieldName).toString();
        QString qstrDescription = _query->value(fieldDescription).toString();
        std::string name = string((const char *)qstrName.toLocal8Bit());
        std::string description = string((const char *)qstrDescription.toLocal8Bit());

        Meal * meal = new Meal(id,name,description,price);
        (*mealList)[id] = meal;
    }

    return mealList;
}


