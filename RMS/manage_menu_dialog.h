#ifndef MANAGE_MENU_DIALOG_H
#define MANAGE_MENU_DIALOG_H

#include <QDialog>

namespace Ui {
class ManageMenuDialog;
}

class ManageMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageMenuDialog(QWidget *parent = nullptr);
    ~ManageMenuDialog();

private:
    Ui::ManageMenuDialog *ui;
};

#endif // MANAGE_MENU_DIALOG_H
