#include "seat_dao.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>
using std::string;

SeatDao::SeatDao(string path): _path(path)
{

}

string SeatDao::getPath(){
    return _path;
}

std::map<int,Seat *> * SeatDao::getSeatList(){
    std::map<int,Seat *> *seatList = new std::map<int,Seat *>();
    QSqlDatabase mydb;


    QString bFile = QString(QString::fromLocal8Bit(_path.c_str()));
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(bFile);
    if(!mydb.open()){
        throw std::string("打開資料庫失敗");
    }

    QSqlTableModel tableModel(nullptr,mydb);

    QSqlQuery query;
    query.exec("select * from seat");

    while(query.next())
    {
        int rowNum = query.at();
        //int columnNum = query.record().count();
        int fieldId = query.record().indexOf("id");
        int fieldUsed = query.record().indexOf("used");
        int fieldTableName = query.record().indexOf("tableName");

        int id = query.value(fieldId).toInt();
        int used = query.value(fieldUsed).toInt();
        QString qstrTableName = query.value(fieldTableName).toString();
        std::string tableName = string((const char *)qstrTableName.toLocal8Bit());

        std::cout<<"id = "<<id<<"  name = "<<tableName<<std::endl;
        Seat * seat = new Seat(id,used,tableName);
        (*seatList)[id] = seat;
    }

    return seatList;
}
