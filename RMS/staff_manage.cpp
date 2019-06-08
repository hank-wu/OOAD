#include "staff_manage.h"
#include "ui_staff_manage.h"
#include <QHostInfo>
#include <QInputDialog>
#include <QMessageBox>

StaffManage::StaffManage(QWidget *parent, RMSHandler *rmsHandler) :
    QWidget(parent),
    ui(new Ui::StaffManage),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    _rmsHandler->refreshMenu();
    _rmsHandler->refreshSeatOrderList();

    _rmsHandler->SetSocketLisener(this,SLOT(onReceiveSocket(QString)));
    _seatOrederList = _rmsHandler->showSeatOrderList();

    refreshSeatName();
    refreshSeat();
    refreshSeatCombo();

    refreshCargoTable();
}

StaffManage::~StaffManage()
{
    delete ui;
}

void StaffManage::refreshSeatName(){
    std::string stdSeatName = (*_seatOrederList)[1]->getTableName();
    QString seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatOne->setText(seatName);
    stdSeatName = (*_seatOrederList)[2]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatTwo->setText(seatName);
    stdSeatName = (*_seatOrederList)[3]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatThree->setText(seatName);
    stdSeatName = (*_seatOrederList)[4]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatFour->setText(seatName);
    stdSeatName = (*_seatOrederList)[5]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatFive->setText(seatName);
    stdSeatName = (*_seatOrederList)[6]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatSix->setText(seatName);
    stdSeatName = (*_seatOrederList)[7]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatSeven->setText(seatName);
    stdSeatName = (*_seatOrederList)[8]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatEight->setText(seatName);
    stdSeatName = (*_seatOrederList)[9]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatNine->setText(seatName);
    stdSeatName = (*_seatOrederList)[10]->getTableName();
    seatName = QString::fromLocal8Bit(stdSeatName.c_str());
    ui->seatTen->setText(seatName);
}

void StaffManage::setSeatContent(QPushButton *status, QTextBrowser *content, int id){
    status->setStyleSheet("background-color: rgb(255, 100, 100);");
    std::map<int ,OrderItem *> * orderItemList = (*_seatOrederList)[id]->getOrderItemList();
    std::map<int ,OrderItem *>::iterator it;
    QString orderContent;
    for(it = orderItemList->begin();it!=orderItemList->end();it++){
        Meal* meal=it->second->getMeal();
        orderContent += QString::fromLocal8Bit(meal->getName().c_str());
        orderContent += QString("    ");
        orderContent += QString::number(it->second->getQuantity());
        orderContent += QString("份");
        orderContent += QString("\n");
    }
    content->setText(orderContent);
}

void StaffManage::clearSeatContent(QPushButton *status, QTextBrowser *content){
    status->setStyleSheet("background-color: rgb(255, 255, 255);");
    content->clear();
}

void StaffManage::refreshSeatCombo(){
    ui->seatCombo->clear();
    ui->seatCombo->addItem("請選擇座位" ,0);

    for(std::map<int, SeatOrder *>::iterator it = _seatOrederList->begin(); it!=_seatOrederList->end();it++){
        if(it->second->isUsed()){
            Seat * seat= it->second;
            int seatId = seat->getSeatId();
            QString seatName = QString::fromLocal8Bit(seat->getTableName().c_str());
            ui->seatCombo->addItem(seatName, seatId);
        }
    }

}

void StaffManage::refreshSeat(){

    if((*_seatOrederList)[1]->isUsed())
        setSeatContent(ui->seatOne,ui->orderOne,1);
    else
        clearSeatContent(ui->seatOne,ui->orderOne);


    if((*_seatOrederList)[2]->isUsed())
        setSeatContent(ui->seatTwo,ui->orderTwo,2);
    else
        clearSeatContent(ui->seatTwo,ui->orderTwo);

    if((*_seatOrederList)[3]->isUsed())
        setSeatContent(ui->seatThree,ui->orderThree,3);
    else
        clearSeatContent(ui->seatThree,ui->orderThree);

    if((*_seatOrederList)[4]->isUsed())
        setSeatContent(ui->seatFour,ui->orderFour,4);
    else
        clearSeatContent(ui->seatFour,ui->orderFour);

    if((*_seatOrederList)[5]->isUsed())
        setSeatContent(ui->seatFive,ui->orderFive,5);
    else
        clearSeatContent(ui->seatFive,ui->orderFive);

    if((*_seatOrederList)[6]->isUsed())
        setSeatContent(ui->seatSix,ui->orderSix,6);
    else
        clearSeatContent(ui->seatSix,ui->orderSix);

    if((*_seatOrederList)[7]->isUsed())
        setSeatContent(ui->seatSeven,ui->orderSeven,7);
    else
        clearSeatContent(ui->seatSeven,ui->orderSeven);

    if((*_seatOrederList)[8]->isUsed())
        setSeatContent(ui->seatEight,ui->orderEight,8);
    else
        clearSeatContent(ui->seatEight,ui->orderEight);

    if((*_seatOrederList)[9]->isUsed())
        setSeatContent(ui->seatNine,ui->orderNine,9);
    else
        clearSeatContent(ui->seatNine,ui->orderNine);

    if((*_seatOrederList)[10]->isUsed())
        setSeatContent(ui->seatTen,ui->orderTen,10);
    else
        clearSeatContent(ui->seatTen,ui->orderTen);
}

void StaffManage::on_determineButton_clicked(){
//
    if(ui->seatCombo->currentIndex()!=0){
        int seatId = ui->seatCombo->currentData().toInt();
        _rmsHandler->clearSeat(seatId);
        refreshSeat();
        refreshSeatCombo();
        _rmsHandler->notify(QString::number(seatId));
    }
}

void StaffManage::onReceiveSocket(QString input){
    int seatId = input.split("\n")[0].toInt();
    qDebug()<<seatId;
    int selectSeatId = ui->seatCombo->currentData().toInt();

    _rmsHandler->refreshSeatOrder(seatId);
    refreshSeat();
    refreshSeatCombo();
    for(int i = 0; i<ui->seatCombo->count();i++){
        if(selectSeatId == ui->seatCombo->itemData(i).toInt()){
            ui->seatCombo->setCurrentIndex(i);
            break;
        }
    }

    //cargoTable
    ui->cargoTable->clearContents();
    refreshCargoTable();
}

void StaffManage::on_seatCombo_currentIndexChanged(int index)
{
}

void StaffManage::on_addButton_clicked(){
    int curRow = ui->cargoTable->currentRow();
    if(curRow < 0){
        QString dlgTitle = "錯誤";
        QString strInfo = "請先選擇一項貨物";
        QMessageBox::warning(this,dlgTitle,strInfo);
    }
    else{
        int cargoId = ui->cargoTable->item(ui->cargoTable->currentRow(),0)->text().toInt();
        qDebug()<<"cargoId = "<<cargoId;

        QString dlgTitle = "新增貨物輸量";
        QString txtLabel = "貨物編號" + QString::number(cargoId);
        int defaultValue = 10;
        int minValue = 1;
        int maxValue = 200;
        int stepValue = 1;
        bool ok = false;
        int inputValue = QInputDialog::getInt(this,dlgTitle,txtLabel,
                                              defaultValue,minValue,maxValue,
                                              stepValue,&ok);
        if(ok){
            qDebug()<<"cargoid = "<<cargoId;
            qDebug()<<"addAmount = "<<inputValue;
            if(!_rmsHandler->increaseCargoAmount(cargoId,inputValue)){
                QString dlgTitle = "錯誤";
                QString strInfo = "新增失敗";
                QMessageBox::warning(this,dlgTitle,strInfo);
            }
            ui->cargoTable->item(ui->cargoTable->currentRow(),2)->setText(QString::number((*_cargoList)[cargoId]->getAmount()));
        }
    }

}

void StaffManage::on_removeButton_clicked(){

}

void StaffManage::refreshCargoTable(){
    _rmsHandler->refreshCargoList();
    _cargoList = _rmsHandler->getCargoList();
    int index = 0;
    for(std::map<int, Cargo *>::iterator it = _cargoList->begin(); it != _cargoList->end(); it++){
        ui->cargoTable->insertRow(ui->cargoTable->rowCount());
        QString cargoId = QString::number(it->second->getId());
        QString cargoName = QString::fromLocal8Bit(it->second->getName().c_str());
        QString cargoAmount = QString::number(it->second->getAmount());
        ui->cargoTable->setItem(index,0,new QTableWidgetItem(cargoId));
        ui->cargoTable->setItem(index,1,new QTableWidgetItem(cargoName));
        ui->cargoTable->setItem(index,2,new QTableWidgetItem(cargoAmount));
        index++;
    }
    ui->cargoTable->horizontalHeader()->show();
}
