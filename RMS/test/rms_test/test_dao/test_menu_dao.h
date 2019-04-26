#ifndef TEST_MENU_DAO_H
#define TEST_MENU_DAO_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../dao/menu_dao.h"
#include <string>
#include <iostream>
#include <QDebug>

TEST(Testdao, 01)
{
    QSqlDatabase mydb;
    QString bFile = QString("rms.db");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(bFile);
    if(!mydb.open()){
        throw std::string("打開資料庫失敗");
    }

    QSqlQuery * query = new QSqlQuery(mydb);
    MenuDao * menuDao = new MenuDao(query);
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


#endif // TEST_MENU_DAO_H
