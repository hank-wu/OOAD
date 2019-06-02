#ifndef BOSS_MANAGE_H
#define BOSS_MANAGE_H

#include <QWidget>

namespace Ui {
class BossManage;
}

class BossManage : public QWidget
{
    Q_OBJECT

public:
    explicit BossManage(QWidget *parent = nullptr);
    ~BossManage();

private:
    Ui::BossManage *ui;
};

#endif // BOSS_MANAGE_H
