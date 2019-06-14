#ifndef TEST_BOSS_HANDLER_H
#define TEST_BOSS_HANDLER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <string>
#include "../../../dao/menu_dao.h"
#include "../../../boss_handler.h"
#include <QDebug>

class TestBossHandler: public ::testing::Test
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
      menuDao = new MenuDao(query,mydb);
  }

  void TearDown() override{

  }

  QSqlDatabase * mydb;
  QSqlQuery * query;
  MenuDao * menuDao;
};

TEST_F(TestBossHandler, createMeal)
{
    bool createResult = false;
    BossHandler * bossHandler = new BossHandler(menuDao);
    bossHandler->refreshMenu();
    createResult = bossHandler->createMeal("咖哩飯","咖哩粉加飯",70);
    ASSERT_EQ(true,createResult);

    std::map<int,Meal *> *mealList;
    mealList = menuDao->getMealList();
    std::map<int,Meal *>::iterator it = mealList->end();
    it--;
    ASSERT_EQ(QString("咖哩飯"),QString(QString::fromLocal8Bit(it->second->getName().c_str())));

    mealList = bossHandler->showMenu();
    std::map<int,Meal *>::iterator it2 = mealList->end();
    it2--;
    ASSERT_EQ(QString("咖哩飯"),QString(QString::fromLocal8Bit(it2->second->getName().c_str())));

    bool createEmptyResult = false;
    createEmptyResult = bossHandler->createMeal("","",0);
    ASSERT_EQ(false,createEmptyResult);
}

TEST_F(TestBossHandler, editMeal)
{
    BossHandler * bossHandler = new BossHandler(menuDao);
    bossHandler->refreshMenu();
    std::map<int,Meal *> *mealList;
    mealList = menuDao->getMealList();
    std::map<int,Meal *>::iterator it = mealList->end();
    it--;
    bool editResult = false;
    editResult = bossHandler->editMeal(it->first,"炸雞","麵包粉加雞",50);
    ASSERT_EQ(true,editResult);


    mealList = bossHandler->showMenu();
    std::map<int,Meal *>::iterator it2 = mealList->end();
    it2--;
    ASSERT_EQ(QString("炸雞"),QString(QString::fromLocal8Bit(it2->second->getName().c_str())));

    bool editEmptyResult = false;
    editEmptyResult = bossHandler->editMeal(it2->first,"","",0);
    ASSERT_EQ(false,editEmptyResult);
}

TEST_F(TestBossHandler, deleteMeal)
{
    BossHandler * bossHandler = new BossHandler(menuDao);
    bossHandler->refreshMenu();
    std::map<int,Meal *> *mealList;
    mealList = bossHandler->showMenu();
    int preSize = mealList->size();
    std::map<int,Meal *>::iterator it = mealList->end();
    it--;
    bool deleteResult = false;
    deleteResult = bossHandler->deleteMeal(it->first);

    ASSERT_EQ(true,deleteResult);
//    for(it=mealList->begin();it != mealList->end();it++){
//        qDebug()<<it->first;
//        qDebug()<<QString::fromLocal8Bit(it->second->getName().c_str());
//    }
    ASSERT_EQ(preSize-1,mealList->size());
}

#endif // TEST_BOSS_HANDLER_H
