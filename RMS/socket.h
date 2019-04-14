#ifndef SOCKET_H
#define SOCKET_H
#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>

class Socket : public QObject
{
    Q_OBJECT

public:
    Socket();
    void Host(QString&, quint16&);
    bool Connect(QString, quint16);
    void notify(QString);
    bool getConnection();
    bool getHost();
    ~Socket();
private:
    QString GetLocalIP();
    QTcpServer * _server;
    QTcpSocket * _socket = nullptr;
    bool connection = false;
    bool host = false;
signals:
    void received(QString);
    void newConnection();
    void socketConnected();
    void socketDisconnected();
private slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onReceive();
    void onError(QAbstractSocket::SocketError);
};

#endif // SOCKET_H
