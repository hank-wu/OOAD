#ifndef BOSS_MANAGE_H
#define BOSS_MANAGE_H

#include <QWidget>
#include "boss_handler.h"

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
};

#endif // BOSS_MANAGE_H
