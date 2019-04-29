#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "host_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase * mydb;
    QSqlQuery * query;
    SeatDao * seatDao;
    MenuDao * menuDao;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        mydb = new QSqlDatabase( QSqlDatabase::database("qt_sql_default_connection"));
    else{
        QString bFile = QString("rms.db");
        mydb = new QSqlDatabase( QSqlDatabase::addDatabase("QSQLITE"));
        mydb->setDatabaseName(bFile);
    }
    query = new QSqlQuery(*mydb);
    seatDao = new SeatDao(query, mydb);
    menuDao = new MenuDao(query, mydb);

    _rmsHandler = new RMSHandler(seatDao,menuDao);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCustomer_clicked()
{
    lg = new LoginPage(this,_rmsHandler);
    this->hide();
    //this->close();
    lg->exec();
}

void MainWindow::on_btnStaff_clicked()
{
    //StaffManage * sm = new StaffManage(nullptr, _rmsHandler);
    HostDialog * host = new HostDialog(nullptr,_rmsHandler);
    this->hide();
    host->exec();
}

void MainWindow::on_btnBoss_clicked(){

}
