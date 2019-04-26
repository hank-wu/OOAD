#ifndef RMSHANDLER_H
#define RMSHANDLER_H
#include <QApplication>
#include "socket.h"
#include "./dao/menu_dao.h"
#include "./dao/seat_dao.h"
#include "./domain/seat_list.h"
#include "./domain/menu.h"
#include "./domain/order.h"
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
    void notify(QString);
    bool IsConnect();
    bool IsHost();
    void refreshSeatList();
    void refreshMenu();
    std::map<int,Seat *> * showSeatList();
    std::map<int,Meal *> * showMenu();
    void createOrder(int seatId);
    void enterOrderItem(int mealId,int amount);
    void createBill();
    bool pay(int money);
    int getAmount();
    int getBalance();
    Receipt * getReceipt();
    void completeOrder();


private:
    Socket* _socket;
    SeatDao * _seatDao;
    MenuDao * _menuDao;
    SeatList * _seatList;
    Menu * _menu;
    Order * _order;
};

#endif // RMSHANDLER_H
