#ifndef RMSHANDLER_H
#define RMSHANDLER_H
#include <QApplication>
#include "socket.h"
#include "./dao/menu_dao.h"
#include "./dao/seat_dao.h"
#include "./domain/seat_list.h"
#include "./domain/menu.h"
#include "./domain/order.h"
#include "./domain/seat_order_list.h"
#include <map>

class RMSHandler : public QObject
{
public:
    RMSHandler(SeatDao * seatDao, MenuDao * menuDao);
    void Host(QString&, quint16&);
    bool Connect(QString, quint16);
    void SetSocketLisener(const QObject* , const char * );
    void SetNewConnectionListener(const QObject* , const char * );
    void SetConnectedListener(const QObject* , const char * );
    void SetDisconnectedListener(const QObject* , const char * );
    void SetConnectFailListener(const QObject* receiver, const char * member);
    void notify(QString);
    bool IsConnect();
    bool IsHost();
    void refreshSeatList();
    void refreshMenu();
    void refreshSeatOrderList();
    std::map<int,Seat *> * showSeatList();
    std::map<int,Meal *> * showMenu();
    void createOrder(int seatId);
    void cancelOrder();
    void enterOrderItem(int mealId,int amount);
    void createBill();
    bool pay(int money);
    int getAmount();
    int getBalance();
    Receipt * getReceipt();
    void completeOrder();
    void clearSeat(int seatId);
    std::map<int,SeatOrder *> * showSeatOrderList();
    int getOrderSeatId();
    void refreshSeatOrder(int seatId);
    void refreshSeat(int seatId);
    void closeDB();
    bool createMeal(QString name,QString description,int price);
    bool editMeal(int id,QString name,QString description,int price);
    bool deleteMeal(int id);

private:
    Socket* _socket;
    SeatDao * _seatDao;
    MenuDao * _menuDao;
    SeatList * _seatList;
    SeatOrderList * _seatOrderList;
    Menu * _menu;
    Order * _order;

};

#endif // RMSHANDLER_H
