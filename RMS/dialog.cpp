#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>

Dialog::Dialog(QWidget *parent, RMSHandler * rmsHandler) :
    QDialog(parent),
    ui(new Ui::Dialog),
    _rmsHandler(rmsHandler)

{
    ui->setupUi(this);
    ui->okButton->setEnabled(false);
    ui->lineEdit->setValidator( new QIntValidator(0, 10000, this) );
    //connect(ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    int amount = _rmsHandler->getAmount();
    ui->totalAmount->setText(QString::number(amount));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->okButton->setEnabled(true);
}

void Dialog::on_okButton_clicked(){
    int money = ui->lineEdit->text().toInt();
    qDebug()<<"test2"<<money;
    if(_rmsHandler->pay(money)){
        qDebug()<<"test2"<<_rmsHandler->getBalance();
        accept();
    }else{

    }
}

