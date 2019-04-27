#include "login_page.h"
#include "ui_login_page.h"


LoginPage::LoginPage(QWidget *parent,RMSHandler * rmsHandler) :
    QDialog(parent),
    ui(new Ui::LoginPage),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    connect(ui->connectButton,SIGNAL(clicked()),this,SLOT(showCustomerManagePage()));

}

LoginPage::~LoginPage()
{
    delete ui;
}
void LoginPage::showCustomerManagePage()
{
    CustomerManage *cm=new CustomerManage(nullptr,_rmsHandler);
    //this->hide();
    this->close();
    cm->show();
}
