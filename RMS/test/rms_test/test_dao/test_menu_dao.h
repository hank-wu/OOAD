#ifndef TEST_MENU_DAO_H
#define TEST_MENU_DAO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../dao/menu_dao.h"
#include <string>
#include <iostream>
#include <QDebug>

class TestMenuDao: public ::testing::Test
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



TEST_F(TestMenuDao, 01)
{
    MenuDao * menuDao = new MenuDao(query,mydb);
    std::map<int,Meal *> *mealList;
    try {
        mealList = menuDao->getMealList();
    } catch (std::string error) {
        ASSERT_EQ("打開資料庫失敗",error);
    }
    ASSERT_EQ(100,(*mealList)[1]->getPrice());

//    QString mealName = QString(QString::fromLocal8Bit((*mealList)[1]->getName().c_str()));
//    qDebug()<<"mealName = "<<mealName<<endl;
}

TEST_F(TestMenuDao, createMeal)
{
    MenuDao * menuDao = new MenuDao(query,mydb);
    QString qstrName = "咖哩飯";
    QString qstrDescription = "咖哩粉加飯";
    bool result = false;
    result = menuDao->createMeal(qstrName,qstrDescription,70);
    ASSERT_EQ(true,result);
    std::map<int,Meal *> *mealList;
    mealList = menuDao->getMealList();

    std::map<int,Meal *>::iterator it = mealList->end();
    it--;
    ASSERT_EQ(QString("咖哩飯"),QString(QString::fromLocal8Bit(it->second->getName().c_str())));
}

TEST_F(TestMenuDao, editMeal)
{
    MenuDao * menuDao = new MenuDao(query,mydb);
    QString qstrName = "炸雞";
    QString qstrDescription = "麵包粉加雞";
    bool result = false;
    result = menuDao->editMeal(11,qstrName,qstrDescription,50);
    ASSERT_EQ(true,result);
    std::map<int,Meal *> *mealList;
    mealList = menuDao->getMealList();

    ASSERT_EQ(QString("炸雞"),QString(QString::fromLocal8Bit((*mealList)[11]->getName().c_str())));

}

TEST_F(TestMenuDao, deleteMeal)
{
    MenuDao * menuDao = new MenuDao(query,mydb);
    bool result = false;
    result = menuDao->deleteMeal(11);
    ASSERT_EQ(true,result);
    std::map<int,Meal *> *mealList;
    mealList = menuDao->getMealList();

    ASSERT_EQ(10,mealList->size());

}


#endif // TEST_MENU_DAO_H
