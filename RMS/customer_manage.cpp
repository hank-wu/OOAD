#include "customer_manage.h"
#include "ui_customer_manage.h"
#include "dialog.h"
#include <QtSql/QtSql>
CustomerManage::CustomerManage(QWidget *parent,RMSHandler * rmsHandler) :
    QWidget(parent),
    ui(new Ui::CustomerManage),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    init();
    connect(ui->ensureBtn,SIGNAL(pressed()),this,SLOT(ensureSeat()));
    connect(ui->seatCombo,SIGNAL(activated(int)),this,SLOT(clickedaction(int)));
    //connect(ui->addBtn,SIGNAL(pressed()),this,SLOT(addToTable()));
    connect(ui->payBtn,SIGNAL(pressed()),this,SLOT(showTotalAmount()));


}

CustomerManage::~CustomerManage()
{
    delete ui;
}
void CustomerManage::ensureSeat()
{
    if(ui->seatCombo->currentText()!="請選擇座位"){
        ui->seatCombo->setDisabled(true);
        ui->mealCombo->setDisabled(false);
        ui->amountCombo->setDisabled(false);
        //ui->addBtn->setDisabled(false);
        //ui->deleBtn->setDisabled(false);
    }
}
void CustomerManage::clickedaction(int currentIndex)
{
    ui->seatCombo->setCurrentIndex(currentIndex);
}
void CustomerManage::addToTable()
{
       ui->payBtn->setDisabled(false);
       //ui->tableWidget->insertRow (ui-> tableWidget->rowCount());
       //ui->tableWidget->setItem( i,0,new QTableWidgetItem(ui->mealCombo->currentText()));
       //ui->tableWidget->setItem( i,1,new QTableWidgetItem(ui->amountCombo->currentText()));
       i++;
}

void CustomerManage::showTotalAmount()
{
   Dialog *d=new Dialog;
   d->exec();
   init();
   delete d;
}
////        switch (ui->seatCombo->currentIndex()) {
////        case 1:
////               ui->pushButton->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 2:
////               ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 3:
////               ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 4:
////               ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 5:
////               ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 6:
////               ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 7:
////               ui->pushButton_7->setStyleSheet("background-color: rgb(255, 0, 0);");
////               break;
////       case 8:
////               ui->pushButton_8->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 9:
////               ui->pushButton_9->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;
////        case 10:
////               ui->pushButton_10->setStyleSheet("background-color: rgb(255, 0, 0);");
////                break;

////        ui->label_3->setText("100000");




void  CustomerManage::init()
{
    ui->mealCombo->setDisabled(false);
     ui->seatCombo->setDisabled(false);
    ui->amountCombo->setDisabled(true);
    //ui->addBtn->setDisabled(true);
    //ui->deleBtn->setDisabled(true);
    ui->payBtn->setDisabled(true);
    ui->mealCombo->setCurrentIndex(0);
    ui->seatCombo->setCurrentIndex(0);
    ui->amountCombo->setCurrentIndex(0);
    //ui-> tableWidget->setRowCount(0);
    i=0;
}
