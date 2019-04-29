#ifndef TEST_RMS_HANDLER_H
#define TEST_RMS_HANDLER_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <string>
#include "../../../dao/seat_dao.h"
#include "../../../dao/menu_dao.h"
#include "../../../rmshandler.h"

class TestRMSHandler: public ::testing::Test
{
protected:
  void SetUp() override
  {
      if(QSqlDatabase::contains("qt_sql_default_connection"))
          mydb = new QSqlDatabase( QSqlDatabase::database("qt_sql_default_connection"));
      else{
          QString bFile = QString("rms.db");
          mydb = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE"));
          mydb->setDatabaseName(bFile);
          if(!mydb->open()){
              throw std::string("打開資料庫失敗");
          }
      }
      query = new QSqlQuery(*mydb);
      seatDao = new SeatDao(query,mydb);
      menuDao = new MenuDao(query,mydb);
  }

  void TearDown() override{

  }

  QSqlDatabase * mydb;
  QSqlQuery * query;
  SeatDao * seatDao;
  MenuDao * menuDao;
};

TEST_F(TestRMSHandler, showSeatList)
{
    RMSHandler * rmsHandler = new RMSHandler(seatDao,menuDao);
    rmsHandler->refreshSeatList();
    std::map<int,Seat *> * seats = rmsHandler->showSeatList();
    ASSERT_EQ(true,(*seats)[1]->isUsed());
    ASSERT_EQ(false,(*seats)[2]->isUsed());
}

TEST_F(TestRMSHandler, showMenu)
{
    RMSHandler * rmsHandler = new RMSHandler(seatDao,menuDao);
    rmsHandler->refreshMenu();
    std::map<int,Meal *> * mealList  = rmsHandler->showMenu();
    ASSERT_EQ(100,(*mealList)[1]->getPrice());
    ASSERT_EQ(30,(*mealList)[2]->getPrice());
}

TEST_F(TestRMSHandler, order)
{
    RMSHandler * rmsHandler = new RMSHandler(seatDao,menuDao);
    rmsHandler->refreshMenu();
    rmsHandler->refreshSeatList();
    rmsHandler->createOrder(3);
    rmsHandler->enterOrderItem(4,1);
    rmsHandler->enterOrderItem(5,2);
    ASSERT_EQ(260,rmsHandler->getAmount());
    rmsHandler->createBill();
    rmsHandler->pay(300);
    ASSERT_EQ(40,rmsHandler->getBalance());
    Receipt * receipt = rmsHandler->getReceipt();
    ASSERT_EQ("A3",receipt->getTableName());
    //qDebug()<<"aaa001 = "<<QString(QString::fromLocal8Bit(receipt->content().c_str()));
    ASSERT_EQ(QString("餛飩麵  80\n排骨飯  180\n"),QString(QString::fromLocal8Bit(receipt->content().c_str())));
    rmsHandler->completeOrder();

    std::map<int,Seat *> * seats = rmsHandler->showSeatList();
    ASSERT_EQ(true,(*seats)[3]->isUsed());
}

#endif // TEST_RMS_HANDLER_H
