#include "boss_manage.h"
#include "ui_boss_manage.h"

BossManage::BossManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossManage)
{
    ui->setupUi(this);
}

BossManage::~BossManage()
{
    delete ui;
}
