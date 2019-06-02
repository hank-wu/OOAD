#include "manage_menu_dialog.h"
#include "ui_manage_menu_dialog.h"

ManageMenuDialog::ManageMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageMenuDialog)
{
    ui->setupUi(this);

}

ManageMenuDialog::~ManageMenuDialog()
{
    delete ui;
}
