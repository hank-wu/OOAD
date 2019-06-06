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
    ~ManageMenuDialog();

private:
    Ui::ManageMenuDialog *ui;
    BossHandler * _bossHandler;

private slots:
    void on_okButton_clicked();
};

#endif // MANAGE_MENU_DIALOG_H
