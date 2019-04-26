#ifndef CUSTOMER_MANAGE_H
#define CUSTOMER_MANAGE_H
#include <QMessageBox>
#include <QWidget>
#include "rmshandler.h"

namespace Ui {
class CustomerManage;
}

class CustomerManage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerManage(QWidget *parent,RMSHandler * rmsHandler);
    ~CustomerManage();
private slots:
    void clickedaction(int currentIndex);
    void addToTable();
    void showTotalAmount();
    void ensureSeat();

private:
    Ui::CustomerManage *ui;
    QList<QString> tm_contact_name;
    QList<QString> tm_contact_amount;
    QMessageBox q;
    int i;
    bool DBConnection(QStringList &List);
    void init();
    RMSHandler * _rmsHandler;
};

#endif // CUSTOMER_MANAGE_H
