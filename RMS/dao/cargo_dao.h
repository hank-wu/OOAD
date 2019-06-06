#ifndef CARGO_DAO_H
#define CARGO_DAO_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <string>
#include "../domain/cargo.h"
#include <map>
#include <vector>
using std::string;

class CargoDao
{
public:
    CargoDao(QSqlQuery * query, QSqlDatabase * mydb);
    std::map<int,Cargo *> * getCargoList();
    void refresh(int id,int amount);
    void closeDB();

private:
    string _path;
    QSqlQuery * _query;
    QSqlDatabase *_mydb;
};

#endif // CARGO_DAO_H
