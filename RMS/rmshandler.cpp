#include "rmshandler.h"
#include "socket.h"
#include <QApplication>

RMSHandler::RMSHandler()
{
    _socket = new Socket();
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
