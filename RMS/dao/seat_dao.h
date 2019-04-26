#ifndef SEAT_DAO_H
#define SEAT_DAO_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <string>
#include "../domain/seat.h"
#include "../domain/order_pair.h"
#include <map>
#include <vector>
using std::string;

class SeatDao
{
public:
    SeatDao(QSqlQuery * query);
    std::map<int,Seat *> * getSeatList();
    Seat * getSeat(int inputId);
    void clearSeat(int inputId);
    void setSeatUsed(int inputId);
    void setSeatOrderPair(int inputId,std::vector<OrderPair> * vecOrderPair);
    std::vector<OrderPair> * getOrderPair(int inputId);

private:
    string _path;
    QSqlQuery * _query;

};

#endif // SEAT_DAO_H
