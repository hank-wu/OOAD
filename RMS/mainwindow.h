#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "rmshandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString localIP;
    RMSHandler* _RMSHandler;

private slots:
    void newConnection();
    void onConnected();
    void onDisconnected();
    void onSocketReadyRead(QString);
    void on_actConnect_triggered();
    void on_actHost_triggered();
    void on_btnSend_clicked();
};

#endif // MAINWINDOW_H
