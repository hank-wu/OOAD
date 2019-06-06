#include "boss_manage.h"
#include "ui_boss_manage.h"
#include <QDebug>
#include <QMessageBox>

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
    connect(_manageMenuDialog, SIGNAL(accepted()), this, SLOT(manageMenuSuccess()));
    connect(_manageMenuDialog, SIGNAL(rejected()), this, SLOT(cancelMenu()));
    _manageMenuDialog->exec();
}

void BossManage::on_editBtn(){
    qDebug()<<"row = "<<ui->menuTable->currentRow();
    int mealId = ui->menuTable->currentRow()+1;
    QString mealName = QString::fromLocal8Bit( (*_mealList)[mealId]->getName().c_str() );
    QString mealDescription = QString::fromLocal8Bit( (*_mealList)[mealId]->getDescription().c_str() );
    int mealPrice = (*_mealList)[mealId]->getPrice();
    _manageMenuDialog = new ManageMenuDialog(this,_bossHandler,
                                             mealId,
                                             mealName,
                                             mealDescription,
                                             mealPrice);
    connect(_manageMenuDialog, SIGNAL(accepted()), this, SLOT(manageMenuSuccess()));
    connect(_manageMenuDialog, SIGNAL(rejected()), this, SLOT(cancelMenu()));
    _manageMenuDialog->exec();
}

void BossManage::on_deleteBtn(){
    qDebug()<<"delete row = "<<ui->menuTable->currentRow();
    int mealId = ui->menuTable->currentRow()+1;
    if(mealId < 1){
        QString dlgTitle = "錯誤";
        QString strInfo = "請選點選要刪除行";
        QMessageBox::warning(this,dlgTitle,strInfo);
    }
    else{
        QMessageBox::StandardButton button;
        button = QMessageBox::warning(this, tr("刪除提醒"),
            QString(tr("確認要刪除?")),
            QMessageBox::Yes | QMessageBox::No);
        if (button == QMessageBox::Yes) {
            /*bool result = _bossHandler->deleteMeal(mealId);
            qDebug()<<"delete result = "<<result;
            if(!result){
                QMessageBox::StandardButton button;
                button = QMessageBox::warning(this, tr("錯誤"),
                    QString(tr("資料庫更新失敗!")),
                    QMessageBox::Yes);
                return;
            }*/
            _bossHandler->deleteMeal(mealId);
            ui->menuTable->clearContents();
            refreshMenuTable();
        }
    }
}

void BossManage::manageMenuSuccess(){
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
        qDebug()<<"name = "<<name;
        ui->menuTable->setItem(index,0,new QTableWidgetItem(name));
        ui->menuTable->setItem(index,1,new QTableWidgetItem(price));
        ui->menuTable->setItem(index,2,new QTableWidgetItem(description));
        index++;
    }
    ui->menuTable->horizontalHeader()->show();
}
