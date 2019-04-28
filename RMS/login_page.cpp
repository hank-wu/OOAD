#include "login_page.h"
#include "ui_login_page.h"


LoginPage::LoginPage(QWidget *parent,RMSHandler * rmsHandler) :
    QDialog(parent),
    ui(new Ui::LoginPage),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(showCustomerManagePage()));
    _rmsHandler->SetConnectedListener(this, SLOT(onConnect()));
    _rmsHandler->SetConnectFailListener(this, SLOT(onConnectFail()));
}

LoginPage::~LoginPage()
{
    delete ui;
}
void LoginPage::showCustomerManagePage()
{
    QString IP = ui->IPInput->text();
    int port = ui->portInput->text().toInt();
    ui->IPInput->clear();
    ui->portInput->clear();
    ui->connectButton->setDisabled(true);
    _rmsHandler->Connect(IP,port);
}

void LoginPage::onConnect(){
    CustomerManage *cm=new CustomerManage(nullptr,_rmsHandler);
    //this->hide();
    this->close();
    cm->show();
}

void LoginPage::onConnectFail(){
    ui->connectButton->setDisabled(false);
    qDebug() << "connect fail222";
}
