#ifndef BOSS_MANAGE_H
#define BOSS_MANAGE_H

#include <QWidget>
#include "boss_handler.h"
#include "manage_menu_dialog.h"

namespace Ui {
class BossManage;
}

class BossManage : public QWidget
{
    Q_OBJECT

public:
    explicit BossManage(QWidget *parent, BossHandler * bossHandler);
    ~BossManage();

private:
    Ui::BossManage *ui;
    BossHandler * _bossHandler;
    std::map<int, Meal * > * _mealList;
    ManageMenuDialog * _manageMenuDialog;
    void refreshMenuTable();

private slots:
    void on_createBtn();
    void on_editBtn();
    void on_deleteBtn();
    void manageMenuSuccess();
    void cancelMenu();
};

#endif // BOSS_MANAGE_H
