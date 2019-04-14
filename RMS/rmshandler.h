#ifndef RMSHANDLER_H
#define RMSHANDLER_H
#include <QApplication>
#include "socket.h"

class RMSHandler : public QObject
{
public:
    RMSHandler();
    void Host(QString&, quint16&);
    bool Connect(QString, quint16);
    void SetSocketLisener(const QObject* , const char * );
    void SetNewConnectionListener(const QObject* , const char * );
    void SetConnectedListener(const QObject* , const char * );
    void SetDisconnectedListener(const QObject* , const char * );
    void notify(QString);
    bool IsConnect();
    bool IsHost();
private:
    Socket* _socket;
};

#endif // RMSHANDLER_H
