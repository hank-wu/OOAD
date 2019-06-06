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

    _manageType = 1;//create
}

ManageMenuDialog::ManageMenuDialog(QWidget *parent, BossHandler * bossHandler,
                                   int mealId,
                                  QString mealName,
                                  QString mealDescription,
                                  int mealPrice) :
    QDialog(parent),
    ui(new Ui::ManageMenuDialog),
    _bossHandler(bossHandler),
    _mealId(mealId)
{
    ui->setupUi(this);
    ui->mealPriceInput->setValidator(new QIntValidator(0, 10000, this));

    ui->mealNameInput->setText(mealName);
    ui->mealDrescribeInput->setText(mealDescription);
    ui->mealPriceInput->setText(QString::number(mealPrice));
    _manageType = 2;//edit
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
        button = QMessageBox::warning(this, tr("錯誤"),
            QString(tr("餐點名稱為必填欄位!")),
            QMessageBox::Yes);
    }else{
        bool result = false;
        if(_manageType == 1)
            result = _bossHandler->createMeal(mealName,mealDescription,mealPrice);
        else if(_manageType == 2)
            result = _bossHandler->editMeal(_mealId,mealName,mealDescription,mealPrice);

        if(!result){
            QMessageBox::StandardButton button;
            button = QMessageBox::warning(this, tr("錯誤"),
                QString(tr("資料庫更新失敗!")),
                QMessageBox::Yes);
            return;
        }
        accept();
    }
}
