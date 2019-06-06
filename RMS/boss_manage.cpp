#include "boss_manage.h"
#include "ui_boss_manage.h"
#include <QDebug>

BossManage::BossManage(QWidget *parent, BossHandler * bossHandler) :
    QWidget(parent),
    ui(new Ui::BossManage),
    _bossHandler(bossHandler)
{
    ui->setupUi(this);
    connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(on_createBtn()));
    connect(ui->ModifyButton,SIGNAL(clicked()),this,SLOT(on_editBtn()));
    connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(on_deleteBtn()));

    bossHandler->refreshMenu();
    _mealList = bossHandler->showMenu();
    refreshMenuTable();
}

BossManage::~BossManage()
{
    delete ui;
}

void BossManage::on_createBtn(){
    qDebug()<<"row = "<<ui->menuTable->currentRow();
    _manageMenuDialog = new ManageMenuDialog(this,_bossHandler);
    connect(_manageMenuDialog, SIGNAL(accepted()), this, SLOT(createMenuSuccess()));
    connect(_manageMenuDialog, SIGNAL(rejected()), this, SLOT(cancelMenu()));
    _manageMenuDialog->exec();
}

void BossManage::on_editBtn(){

}

void BossManage::on_deleteBtn(){

}

void BossManage::createMenuSuccess(){
    ui->menuTable->clearContents();
    refreshMenuTable();
    delete _manageMenuDialog;
}

void BossManage::cancelMenu(){
    qDebug()<<"cancel";
    delete _manageMenuDialog;
}

void BossManage::refreshMenuTable(){
    int index = 0;
    for(std::map<int, Meal * >::iterator it = _mealList->begin(); it != _mealList->end();it++){
        ui->menuTable->insertRow(ui->menuTable->rowCount());
        QString name = QString::fromLocal8Bit(it->second->getName().c_str());
        QString price = QString::number(it->second->getPrice());
        QString description = QString::fromLocal8Bit(it->second->getDescription().c_str());
        ui->menuTable->setItem(index,0,new QTableWidgetItem(name));
        ui->menuTable->setItem(index,1,new QTableWidgetItem(price));
        ui->menuTable->setItem(index,2,new QTableWidgetItem(description));
        index++;
    }
    ui->menuTable->horizontalHeader()->show();
}
