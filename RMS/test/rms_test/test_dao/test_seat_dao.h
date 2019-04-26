#ifndef TEST_SEAT_DAO_H
#define TEST_SEAT_DAO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../dao/seat_dao.h"
#include <string>
#include <iostream>
#include <QDebug>

class TestSeatDao: public ::testing::Test
{
protected:
  void SetUp() override
  {
      if(QSqlDatabase::contains("qt_sql_default_connection"))
          mydb = QSqlDatabase::database("qt_sql_default_connection");
      else{
          QString bFile = QString("rms.db");
          mydb = QSqlDatabase::addDatabase("QSQLITE");
          mydb.setDatabaseName(bFile);
          if(!mydb.open()){
              throw std::string("打開資料庫失敗");
          }
      }
      query = new QSqlQuery(mydb);
  }

  void TearDown() override{

  }

  QSqlDatabase mydb;
  QSqlQuery * query;

};


TEST_F(TestSeatDao, getSeatList)
{
    SeatDao * seatDao = new SeatDao(query);
    std::map<int,Seat *> *seatList;
    seatList = seatDao->getSeatList();
    ASSERT_EQ(true,(*seatList)[1]->isUsed());

}

TEST_F(TestSeatDao, getSeat)
{
    SeatDao * seatDao = new SeatDao(query);
    Seat * seat;
    seat = seatDao->getSeat(4);
    ASSERT_EQ(4,seat->getSeatId());
}

TEST_F(TestSeatDao, clearSeat)
{
    SeatDao * seatDao = new SeatDao(query);
    Seat * seat;
    seatDao->clearSeat(7);
    seat = seatDao->getSeat(7);
    ASSERT_EQ(false,seat->isUsed());
}

TEST_F(TestSeatDao, clearSeat2)
{
    SeatDao * seatDao = new SeatDao(query);
    Seat * seat;
    seatDao->clearSeat(3);
    seat = seatDao->getSeat(3);
    ASSERT_EQ(false,seat->isUsed());

    std::vector<OrderPair> * vecOrderPair;
    vecOrderPair = seatDao->getOrderPair(3);
    ASSERT_EQ(0,vecOrderPair->size());
}

TEST_F(TestSeatDao, setSeatisUsed)
{
    SeatDao * seatDao = new SeatDao(query);
    Seat * seat;
    seatDao->setSeatUsed(7);
    seat = seatDao->getSeat(7);
    ASSERT_EQ(true,seat->isUsed());
    seatDao->clearSeat(7);
}

TEST_F(TestSeatDao, getOrderPair)
{
    SeatDao * seatDao = new SeatDao(query);

    std::vector<OrderPair> * vecOrderPair;
    vecOrderPair = seatDao->getOrderPair(2);

    ASSERT_EQ(0,vecOrderPair->size());

    vecOrderPair = seatDao->getOrderPair(1);
    ASSERT_EQ(1,(*vecOrderPair)[0].getId());
    ASSERT_EQ(1,(*vecOrderPair)[0].getAmount());
    ASSERT_EQ(2,(*vecOrderPair)[1].getId());
    ASSERT_EQ(2,(*vecOrderPair)[1].getAmount());
    ASSERT_EQ(3,(*vecOrderPair)[2].getId());
    ASSERT_EQ(2,(*vecOrderPair)[2].getAmount());
}

TEST_F(TestSeatDao, setSeatOrderPair)
{
    OrderPair orderPairOne(5,8);
    OrderPair orderPairTwo(6,9);
    SeatDao * seatDao = new SeatDao(query);
    std::vector<OrderPair> * vecOrderPair = new std::vector<OrderPair>();
    vecOrderPair->push_back(orderPairOne);
    vecOrderPair->push_back(orderPairTwo);
    seatDao->setSeatOrderPair(6,vecOrderPair);

    std::vector<OrderPair> * vecOrderPairTwo;
    vecOrderPairTwo = seatDao->getOrderPair(6);
    ASSERT_EQ(5,(*vecOrderPairTwo)[0].getId());
    ASSERT_EQ(8,(*vecOrderPairTwo)[0].getAmount());
    ASSERT_EQ(6,(*vecOrderPairTwo)[1].getId());
    ASSERT_EQ(9,(*vecOrderPairTwo)[1].getAmount());

}

#endif // TEST_SEAT_DAO_H
