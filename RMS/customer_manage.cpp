#include "customer_manage.h"
#include "ui_customer_manage.h"
#include "dialog.h"
#include <QtDebug>

CustomerManage::CustomerManage(QWidget *parent,RMSHandler * rmsHandler) :
    QWidget(parent),
    ui(new Ui::CustomerManage),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    init();
    connect(ui->ensureBtn,SIGNAL(clicked()),this,SLOT(ensureSeat()));
    connect(ui->seatCombo,SIGNAL(activated(int)),this,SLOT(clickedaction(int)));
    connect(ui->enterOrderBtn,SIGNAL(clicked()),this,SLOT(addToTable()));
    connect(ui->payBtn,SIGNAL(clicked()),this,SLOT(showTotalAmount()));
    rmsHandler->refreshMenu();
    rmsHandler->refreshSeatList();

    //reset menu
    _mealList = rmsHandler->showMenu();
    int index = 0;
    for(std::map<int, Meal * >::iterator it = _mealList->begin(); it != _mealList->end();it++){
        ui->menuTable->insertRow(ui->menuTable->rowCount());
        qDebug()<<"test"<<ui->menuTable->rowCount();
        QString name = QString::fromLocal8Bit(it->second->getName().c_str());
        QString price = QString::number(it->second->getPrice());
        QString description = QString::fromLocal8Bit(it->second->getDescription().c_str());
        ui->menuTable->setItem(index,0,new QTableWidgetItem(name));
        ui->menuTable->setItem(index,1,new QTableWidgetItem(price));
        ui->menuTable->setItem(index,2,new QTableWidgetItem(description));
        index++;
        ui->mealCombo->addItem(QString(name),it->second->getId());
    }
    ui->menuTable->horizontalHeader()->show();
    ui->orderTable->horizontalHeader()->show();
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
    int mealId = ui->mealCombo->currentData().toInt();
    int index = ui->orderTable->rowCount();
    ui->orderTable->insertRow(ui->orderTable->rowCount());
    QString name = QString::fromLocal8Bit((*_mealList)[mealId]->getName().c_str());
    ui->orderTable->setItem(index,0,new QTableWidgetItem(name));
    ui->orderTable->setItem(index,1,new QTableWidgetItem(QString("test")));
    ui->orderTable->setItem(index,2,new QTableWidgetItem(QString("test")));
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
