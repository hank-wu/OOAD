#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->okButton->setEnabled(false);
    ui->lineEdit->setValidator( new QIntValidator(0, 10000, this) );
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
       ui->okButton->setEnabled(true);
}
