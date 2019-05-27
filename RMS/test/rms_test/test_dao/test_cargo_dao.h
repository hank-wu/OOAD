#ifndef TEST_CARGO_DAO_H
#define TEST_CARGO_DAO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../dao/cargo_dao.h"
#include <string>
#include <iostream>
#include <QDebug>

class TestCargoDao: public ::testing::Test
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
  }

  void TearDown() override{

  }

  QSqlDatabase * mydb;
  QSqlQuery * query;

};

TEST_F(TestCargoDao, getCargoList)
{
    CargoDao * cargoDao = new CargoDao(query,mydb);
    std::map<int,Cargo *> * cargoList;
    cargoList = cargoDao->getCargoList();
    ASSERT_EQ(QString("豆皮壽司貨物"),QString(QString::fromLocal8Bit((*cargoList)[2]->getName().c_str())));
}

TEST_F(TestCargoDao, refresh)
{
    CargoDao * cargoDao = new CargoDao(query,mydb);
    cargoDao->refresh(1,10);
    std::map<int,Cargo *> * cargoList;
    cargoList = cargoDao->getCargoList();
    ASSERT_EQ(10,(*cargoList)[1]->getAmount());
    cargoDao->refresh(1,0);
}

#endif // TEST_CARGO_DAO_H
