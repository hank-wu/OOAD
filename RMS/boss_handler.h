#ifndef BOSS_HANDLER_H
#define BOSS_HANDLER_H

//#include <QString>
#include "./dao/menu_dao.h"
#include "./domain/menu.h"
#include <string>
#include <map>
class BossHandler
{
public:
    BossHandler(MenuDao * menuDao);
    void refreshMenu();
    std::map<int,Meal *> * showMenu();
    bool createMeal(QString name, QString description, int price);
    bool editMeal(int id, QString name, QString description, int price);
    bool deleteMeal(int id);

private:
    MenuDao * _menuDao;
    Menu * _menu;
};

#endif // BOSS_HANDLER_H
