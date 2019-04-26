#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "staff_manage.h"
#include "login_page.h"
#include <QMainWindow>
#include "rmshandler.h"
#include "./dao/menu_dao.h"
#include "./dao/seat_dao.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnCustomer_clicked();
    void on_btnStaff_clicked();
    void on_btnBoss_clicked();

private:
    Ui::MainWindow *ui;
//    StaffManage sm;
    LoginPage * lg;
//    CustomerManage cm;
    RMSHandler * _rmsHandler;



};

#endif // MAINWINDOW_H
