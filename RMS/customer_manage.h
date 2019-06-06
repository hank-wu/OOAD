#ifndef CUSTOMER_MANAGE_H
#define CUSTOMER_MANAGE_H
#include <QMessageBox>
#include <QWidget>
#include "rmshandler.h"
#include "dialog.h"

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
    void addToTable();
    void showTotalAmount();
    void ensureSeat();
    void on_mealCombo_currentIndexChanged(int index);
    void paymentSuccess();
    void cancelPayment();
    void onReceiveSocket(QString input);

private:
    Ui::CustomerManage *ui;
    void initViewStatus();
    void refreshSeat();
    void refreshSeatName();
    RMSHandler * _rmsHandler;
    std::map<int, Meal * > * _mealList;
    std::map<int, Seat * > * _seatList;
    Dialog * payment;
    void refreshSeatCombo();
};

#endif // CUSTOMER_MANAGE_H
