#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostInfo>
#include "socket.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    localIP = getLocalIP();
    _RMSHandler = new RMSHandler();
    _RMSHandler->SetSocketLisener(this, SLOT(onSocketReadyRead(QString)));
    _RMSHandler->SetNewConnectionListener(this, SLOT(newConnection()));
    _RMSHandler->SetConnectedListener(this, SLOT(onConnected()));
    _RMSHandler->SetDisconnectedListener(this, SLOT(onDisConnected()));
    connect(ui->btnConnect,SIGNAL(clicked()),this,SLOT(on_actConnect_triggered()));
    connect(ui->btnHost,SIGNAL(clicked()),this,SLOT(on_actHost_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getLocalIP(){
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

void MainWindow::on_actConnect_triggered(){
    if(!_RMSHandler->IsHost()){
        _RMSHandler->Connect("192.168.56.1",1200);
    }
}

void MainWindow::on_actHost_triggered(){
    if(!_RMSHandler->IsHost()&&!_RMSHandler->IsConnect()){
        QString testIP;
        quint16 testPort;
        _RMSHandler->Host(testIP,testPort);
        qInfo() << "success"<<testIP<<testPort;
        ui->plainTextEdit->appendPlainText("等待連線");
    }
}

void MainWindow::newConnection(){
    ui->plainTextEdit->appendPlainText("有人連上");
}

void MainWindow::onConnected(){
    ui->plainTextEdit->appendPlainText("連線成功");
}

void MainWindow::onDisconnected(){
    ui->plainTextEdit->appendPlainText("斷線成功");
}

void MainWindow::on_btnSend_clicked(){
    if(_RMSHandler->IsConnect()){
        QString msg = ui->lineEdit->text();
        ui->plainTextEdit->appendPlainText("[out] "+msg);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
        _RMSHandler->notify(msg);
    }else{
        ui->plainTextEdit->appendPlainText("未連結");
    }

}


void MainWindow::onSocketReadyRead(QString input){
    ui->plainTextEdit->appendPlainText("[input]" + input);
}
