#ifndef RECEIPT_DILOG_H
#define RECEIPT_DILOG_H

#include <QDialog>
#include "domain/receipt.h"

namespace Ui {
class ReceiptDilog;
}

class ReceiptDilog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiptDilog(QWidget *parent, Receipt * receipt, int balance);
    ~ReceiptDilog();

private:
    Ui::ReceiptDilog *ui;
    Receipt * _receipt;
    int _balance;
};

#endif // RECEIPT_DILOG_H
