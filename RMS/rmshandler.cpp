#include "rmshandler.h"
#include "socket.h"
#include <QApplication>

RMSHandler::RMSHandler(SeatDao * seatDao, MenuDao * menuDao): _seatDao(seatDao), _menuDao(menuDao)
{
    _socket = new Socket();
    _seatList = new SeatList();
    _menu = new Menu();

}

void RMSHandler::Host(QString& IP, quint16& port){
    _socket->Host(IP,port);
}

bool RMSHandler::Connect(QString IP, quint16 port){
    return _socket->Connect(IP,port);
}

void RMSHandler::SetSocketLisener(const QObject * receiver, const char * member){
    connect(_socket,SIGNAL(received(QString)),receiver,member);
}

void RMSHandler::SetNewConnectionListener(const QObject *receiver, const char *member){
    connect(_socket,SIGNAL(newConnection()),receiver,member);
}

void RMSHandler::SetConnectedListener(const QObject *receiver, const char *member){
    connect(_socket,SIGNAL(socketConnected()),receiver,member);
}

void RMSHandler::SetDisconnectedListener(const QObject *receiver, const char *member){
    connect(_socket,SIGNAL(socketDisconnected()),receiver,member);
}

void RMSHandler::notify(QString output){
    _socket->notify(output);
}

bool RMSHandler::IsConnect(){
    return _socket->getConnection();
}

bool RMSHandler::IsHost(){
    return _socket->getHost();
}

void RMSHandler::refreshSeatList(){
    std::map<int,Seat *> * seats = _seatDao->getSeatList();
    _seatList->refresh(seats);
}

std::map<int,Seat *> * RMSHandler::showSeatList(){
    return  _seatList->getAllSeats();
}

void RMSHandler::refreshMenu(){
    std::map<int,Meal *> * mealList = _menuDao->getMealList();
    _menu->refresh(mealList);
}

std::map<int,Meal *> * RMSHandler::showMenu(){
    return  _menu->getMenu();
}

void RMSHandler::createOrder(int seatId){
    Seat * seat = _seatList->getSeat(seatId);
    _order = new Order(seat);
}

void RMSHandler::cancelOrder(){
    delete _order;
}
void RMSHandler::enterOrderItem(int mealId, int amount){
    Meal * meal = _menu->getMeal(mealId);
    _order->add(meal,amount);
}

void RMSHandler::createBill(){
    _order->createBill();
}

bool RMSHandler::pay(int money){
    return _order->pay(money);
}

int RMSHandler::getAmount(){
    return _order->getAmount();
}

int RMSHandler::getBalance(){
    return _order->getBalance();
}

Receipt * RMSHandler::getReceipt(){
    return _order->getReceipt();
}

void RMSHandler::completeOrder(){
    int seatId = _order->getSeatId();
    _seatDao->setSeatUsed(seatId);
    _seatDao->setSeatOrderPair(seatId,_order->getOrderPair());
    Seat * seat = _seatDao->getSeat(seatId);
    _seatList->refresh(seatId,seat);
    delete _order;
}
