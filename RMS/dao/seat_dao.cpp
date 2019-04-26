#include "seat_dao.h"
#include <iostream>
#include <QDebug>
using std::string;

SeatDao::SeatDao(QSqlQuery * query): _query(query)
{

}

std::map<int,Seat *> * SeatDao::getSeatList(){
    std::map<int,Seat *> *seatList = new std::map<int,Seat *>();

    _query->exec("select * from seat");

    while(_query->next())
    {
        int rowNum = _query->at();
        //int columnNum = _query->record().count();
        int fieldId = _query->record().indexOf("id");
        int fieldUsed = _query->record().indexOf("used");
        int fieldTableName = _query->record().indexOf("tableName");

        int id = _query->value(fieldId).toInt();
        int used = _query->value(fieldUsed).toInt();
        QString qstrTableName = _query->value(fieldTableName).toString();
        std::string tableName = string((const char *)qstrTableName.toLocal8Bit());

        //std::cout<<"id = "<<id<<"  name = "<<tableName<<std::endl;
        Seat * seat = new Seat(id,used,tableName);
        (*seatList)[id] = seat;
    }

    return seatList;
}

Seat * SeatDao::getSeat(int inputId){

    Seat * seat = nullptr;

    QString queryStr = "select * from seat where id = " + QString::number(inputId);
    _query->exec(queryStr);

    while(_query->next())
    {
        int fieldId = _query->record().indexOf("id");
        int fieldUsed = _query->record().indexOf("used");

        int id = _query->value(fieldId).toInt();
        int used = _query->value(fieldUsed).toInt();

        //std::cout<<"id = "<<id<<std::endl;
        seat = new Seat(id,used);
    }

    return seat;
}

void SeatDao::clearSeat(int inputId){

    QString queryStr = "UPDATE seat SET used = 0, mealId = NULL, amount = NULL WHERE id = " + QString::number(inputId);
    _query->exec(queryStr);
}

void SeatDao::setSeatUsed(int inputId){

    QString queryStr = "UPDATE seat SET used = 1 WHERE id = " + QString::number(inputId);
    _query->exec(queryStr);
}

void SeatDao::setSeatOrderPair(int inputId,std::vector<OrderPair> *vecOrderPair){
    std::vector<OrderPair>::iterator it;
    QString queryStrOne = "UPDATE seat SET mealId = '";
    QString queryStrTwo = "UPDATE seat SET amount = '";
    for(it = vecOrderPair->begin();it != vecOrderPair->end();it++){
        if(it != vecOrderPair->begin()){
            queryStrOne += ",";
            queryStrTwo += ",";
        }
        queryStrOne += QString::number(it->getId());
        queryStrTwo += QString::number(it->getAmount());
    }
    queryStrOne += "' WHERE id = " + QString::number(inputId);
    queryStrTwo += "' WHERE id = " + QString::number(inputId);
    qDebug() <<queryStrOne<<_query->exec(queryStrOne)<<endl;
    _query->exec(queryStrOne);
    _query->exec(queryStrTwo);
}

std::vector<OrderPair> * SeatDao::getOrderPair(int inputId){

    QString queryStr = "select * from seat where id = " + QString::number(inputId);
    _query->exec(queryStr);

    std::vector<OrderPair> * vecOrderPair = new std::vector<OrderPair>();
    while(_query->next())
    {
        int fieldMealId = _query->record().indexOf("mealId");
        int fieldAmount = _query->record().indexOf("amount");

        QString qstrMealId = _query->value(fieldMealId).toString();
        QString qstrAmount = _query->value(fieldAmount).toString();

        qDebug() << "mealId = "<< qstrMealId<<endl;
        qDebug() << "amount = "<< qstrAmount<<endl;

        if(qstrMealId.compare("") == 0){
            return vecOrderPair;
        }

        QStringList mealIdList = qstrMealId.split(",");
        QStringList amountList = qstrAmount.split(",");

        for(int i=0;i<mealIdList.size();i++){
            OrderPair orderPair(mealIdList.at(i).toInt(),amountList.at(i).toInt());
            vecOrderPair->push_back(orderPair);
            qDebug()<<"meal = "<<mealIdList.at(i)<<" amount = "<<amountList.at(i)<<endl;
        }
        qDebug()<< " mealIdList = "<<mealIdList.size()<<endl;
        //QString mealIdOne = qstrMealId
        //std::cout<<"id = "<<id<<std::endl;
        //seat = new Seat(id,used);
    }

    return vecOrderPair;
}
