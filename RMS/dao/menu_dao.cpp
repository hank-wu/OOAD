#include "menu_dao.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>
using std::string;

MenuDao::MenuDao(string path): _path(path)
{

}

string MenuDao::getPath(){
    return _path;
}

std::map<int,Meal *> * MenuDao::getMealList(){
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();
    QSqlDatabase mydb;


    QString bFile = QString(QString::fromLocal8Bit(_path.c_str()));
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(bFile);
    if(!mydb.open()){
        throw std::string("打開資料庫失敗");
    }

    QSqlTableModel tableModel(nullptr,mydb);

    QSqlQuery query;
    query.exec("select * from menu");

    while(query.next())
    {
        int rowNum = query.at();
        //int columnNum = query.record().count();
        int fieldId = query.record().indexOf("id");
        int fieldName = query.record().indexOf("name");
        int fieldDescription = query.record().indexOf("description");
        int fieldPrice = query.record().indexOf("price");


        int id = query.value(fieldId).toInt();
        int price = query.value(fieldPrice).toInt();
        QString qstrName = query.value(fieldName).toString();
        QString qstrDescription = query.value(fieldDescription).toString();
        std::string name = string((const char *)qstrName.toLocal8Bit());
        std::string description = string((const char *)qstrDescription.toLocal8Bit());

        Meal * meal = new Meal(id,name,description,price);
        (*mealList)[id] = meal;
    }

    mydb.close();
    return mealList;
}


