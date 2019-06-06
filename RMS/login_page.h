#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H
#include "customer_manage.h"
#include <QDialog>
#include "rmshandler.h"
#include <QTcpSocket>

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent,RMSHandler * rmsHandler);
    ~LoginPage();

private slots:
    void showCustomerManagePage();
    void onConnect();
    void onConnectFail();
private:
    Ui::LoginPage *ui;
    RMSHandler * _rmsHandler;

};

#endif // LOGIN_PAGE_H
