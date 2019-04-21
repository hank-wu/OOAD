#ifndef USER_MANAGE_H
#define USER_MANAGE_H

#include <QMainWindow>

namespace Ui {
class UserManage;
}

class UserManage : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserManage(QWidget *parent = nullptr);

    ~UserManage();

private slots:

    void clickedaction(int currentIndex);

private:
    Ui::UserManage *ui;
    QList<QString> tm_contact_name;
    QList<QString> tm_contact_phone;

};

#endif // USER_MANAGE_H
