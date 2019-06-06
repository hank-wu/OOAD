#include "manage_menu_dialog.h"
#include "ui_manage_menu_dialog.h"
#include <QIntValidator>
#include <QMessageBox>

ManageMenuDialog::ManageMenuDialog(QWidget *parent,BossHandler * bossHandler) :
    QDialog(parent),
    ui(new Ui::ManageMenuDialog),
    _bossHandler(bossHandler)
{
    ui->setupUi(this);
    ui->mealPriceInput->setValidator(new QIntValidator(0, 10000, this));

}

ManageMenuDialog::~ManageMenuDialog()
{
    delete ui;
}

void ManageMenuDialog::on_okButton_clicked(){
    QString mealName = ui->mealNameInput->text();
    QString mealDescription = ui->mealDrescribeInput->text();
    int mealPrice = ui->mealPriceInput->text().toInt();


    if(mealName == ""){
        QMessageBox::StandardButton button;
        button = QMessageBox::warning(this, tr("新增失敗"),
            QString(tr("餐點名稱為必填欄位!")),
            QMessageBox::Yes);
    }else{
        bool result = _bossHandler->createMeal(mealName,mealDescription,mealPrice);
        if(!result){
            QMessageBox::StandardButton button;
            button = QMessageBox::warning(this, tr("新增失敗"),
                QString(tr("資料庫新增失敗!")),
                QMessageBox::Yes);
            return;
        }
        accept();
    }
}
