#include "receipt_dilog.h"
#include "ui_receipt_dilog.h"
#include <string>

ReceiptDilog::ReceiptDilog(QWidget *parent, Receipt * receipt, int balance) :
    QDialog(parent),
    ui(new Ui::ReceiptDilog),_receipt(receipt),_balance(balance)
{
    ui->setupUi(this);
    connect(ui->okButton,SIGNAL(clicked()),this, SLOT(accept()));
    std::string tableName = receipt->getTableName();
    QString qTableName = QString::fromUtf8(tableName.c_str());
    ui->tableName->setText(qTableName);
    ui->balance->setText(QString::number(balance));
    QString content =QString::fromLocal8Bit(receipt->content().c_str());
    ui->content->setText(content);
}

ReceiptDilog::~ReceiptDilog()
{
    delete ui;
}
