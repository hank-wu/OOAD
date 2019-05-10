#ifndef TEST_MENU_H
#define TEST_MENU_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../domain/meal.h"
#include "../../../domain/menu.h"
using namespace testing;

TEST(TestMenu, create)
{
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    (*mealList)[1] = meal_one;
    (*mealList)[2] = meal_two;

    Menu * menu = new Menu();
    menu->refresh(mealList);
    ASSERT_EQ(meal_two,menu->getMeal(2));

    menu->createMeal("咖哩飯","咖哩粉加飯",70);
    mealList = menu->getMenu();
    ASSERT_EQ(3,mealList->size());
    ASSERT_EQ("咖哩飯",(*mealList)[3]->getName());

}

TEST(TestMenu, edit)
{
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    (*mealList)[1] = meal_one;
    (*mealList)[2] = meal_two;

    Menu * menu = new Menu();
    menu->refresh(mealList);
    ASSERT_EQ(meal_two,menu->getMeal(2));

    menu->createMeal("咖哩飯","咖哩粉加飯",70);
    mealList = menu->getMenu();
    ASSERT_EQ(3,mealList->size());
    ASSERT_EQ("咖哩飯",(*mealList)[3]->getName());

    menu->editMeal(1,"飯糰","很多飯",30);
    ASSERT_EQ("飯糰",(*mealList)[1]->getName());

}

TEST(TestMenu, delete)
{
    std::map<int,Meal *> *mealList = new std::map<int,Meal *>();
    Meal * meal_one = new Meal(1,"apple","good",10);
    Meal * meal_two = new Meal(2,"banana","yellow",20);
    (*mealList)[1] = meal_one;
    (*mealList)[2] = meal_two;

    Menu * menu = new Menu();
    menu->refresh(mealList);
    ASSERT_EQ(meal_two,menu->getMeal(2));

    menu->createMeal("咖哩飯","咖哩粉加飯",70);
    mealList = menu->getMenu();
    ASSERT_EQ(3,mealList->size());
    ASSERT_EQ("咖哩飯",(*mealList)[3]->getName());

    menu->deleteMeal(1);

    ASSERT_EQ(2,mealList->size());
    ASSERT_EQ("banana",(*mealList)[2]->getName());
    ASSERT_EQ("咖哩飯",(*mealList)[3]->getName());

}

#endif // TEST_MENU_H
