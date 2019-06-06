#ifndef MANAGE_MENU_DIALOG_H
#define MANAGE_MENU_DIALOG_H

#include <QDialog>
#include "boss_handler.h"

namespace Ui {
class ManageMenuDialog;
}

class ManageMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageMenuDialog(QWidget *parent, BossHandler * bossHandler);
    explicit ManageMenuDialog(QWidget *parent, BossHandler * bossHandler,
                              int mealId,
                              QString mealName,
                              QString mealDescription,
                              int mealPrice);
    ~ManageMenuDialog();

private:
    Ui::ManageMenuDialog *ui;
    BossHandler * _bossHandler;
    int _manageType = 0;//1:create,2:edit
    int _mealId;

private slots:
    void on_okButton_clicked();
};

#endif // MANAGE_MENU_DIALOG_H
