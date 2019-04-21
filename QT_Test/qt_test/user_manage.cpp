#include "user_manage.h"
#include "ui_user_manage.h"
#include <math.h>

UserManage::UserManage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserManage)
{
    ui->setupUi(this);
    connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(clickedaction(int)));
    tm_contact_name.append("Thomas");
    tm_contact_name.append("Richard");
    tm_contact_name.append("Harrison");
    tm_contact_phone.append("1");
    tm_contact_phone.append("2");
    tm_contact_phone.append("3");

   for(int i=0;i<tm_contact_name.size();i++)
   {
       ui->tableWidget->insertRow (ui-> tableWidget->rowCount() );

       ui->tableWidget->setItem( i,0,new QTableWidgetItem(tm_contact_name.at(i)));
       ui->tableWidget->setItem( i,1,new QTableWidgetItem(tm_contact_phone.at(i)));
       ui->tableWidget->setItem( i,2,new QTableWidgetItem(tm_contact_name.at(i)));



   }








}

UserManage::~UserManage()
{
    delete ui;
}

void UserManage::clickedaction(int currentIndex) {
    switch (currentIndex) {
    case 1:
           ui->pushButton->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 2:
           ui->pushButton_2->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 3:
           ui->pushButton_3->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 4:
           ui->pushButton_4->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 5:
           ui->pushButton_5->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 6:
           ui->pushButton_6->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 7:
           ui->pushButton_7->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 8:
           ui->pushButton_8->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 9:
           ui->pushButton_9->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;
    case 10:
           ui->pushButton_10->setStyleSheet("background-color: rgb(255, 0, 0);");
            break;

    }
}
