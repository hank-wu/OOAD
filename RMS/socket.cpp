#include "socket.h"
#include <QTcpSocket>
#include <QApplication>
#include <QHostInfo>

Socket::Socket()
{

}

Socket::~Socket()
{
    delete _socket;
    _socket = nullptr;
    delete _server;
    _server = nullptr;
}


void Socket::Host(QString& IP, quint16& port){
    delete _socket;
    _socket = nullptr;
    _server = new QTcpServer();
    host = true;
    connect(_server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    QString localIP = GetLocalIP();
    qInfo() << localIP<<"test2";
    QHostAddress addr(localIP);
    _server->listen(addr, 1200);
    qInfo() << _server->serverAddress().toString()<<"test2";
    IP = _server->serverAddress().toString();
    port = _server->serverPort();
}

bool Socket::Connect(QString IP, quint16 port){
    delete _socket;
    _socket = new QTcpSocket(this);
    connect(_socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(_socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReceive()));
    connect(_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
    _socket->connectToHost(IP,port);
    return true;
}

void Socket::notify(QString output){
    qInfo() << "test";
    QByteArray str = output.toUtf8();
    str.append("\n");
    qInfo() << "nonono"<<_socket->write(str);
}

bool Socket::getConnection(){
    return connection;
}

QString Socket::GetLocalIP(){
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIPqstr = "";
    QList<QHostAddress> addList = hostInfo.addresses();

    if(!addList.isEmpty()){
        for(int i=0;i<addList.count();i++){
            QHostAddress aHost = addList.at(i);
            if( QAbstractSocket::IPv4Protocol == aHost.protocol() ){
                localIPqstr = aHost.toString();
                break;
            }
        }
    }
    return localIPqstr;
}

void Socket::onNewConnection(){
    qInfo() << "success";
    _socket = _server->nextPendingConnection();
    connect(_socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(_socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReceive()));
    connect(_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
    connection = true;
    emit newConnection();
}

void Socket::onConnected(){
    connection = true;
    qInfo() << "connect success";
    emit socketConnected();
}

void Socket::onDisconnected(){
    connection = false;
    qInfo() << "disconnect success";
    emit socketDisconnected();
}

void Socket::onReceive(){
    qInfo() << "receive success";
    QString output;
    while(_socket->canReadLine())
        output +=_socket->readLine();
    emit received(output);
}

void Socket::onError(QAbstractSocket::SocketError socketError){
    qInfo() << "connect fail";
    connection = false;
    emit connectFail();
}

bool Socket::getHost(){
    return host;
}

