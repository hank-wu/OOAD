#include "boss_manage.h"
#include "ui_boss_manage.h"

BossManage::BossManage(QWidget *parent, BossHandler * bossHandler) :
    QWidget(parent),
    ui(new Ui::BossManage),
    _bossHandler(bossHandler)
{
    ui->setupUi(this);
}

BossManage::~BossManage()
{
    delete ui;
}
