#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb;
    QSqlQuery * query;
    SeatDao * seatDao;
    MenuDao * menuDao;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        mydb = QSqlDatabase::database("qt_sql_default_connection");
    else{
        QString bFile = QString("rms.db");
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(bFile);
        if(!mydb.open()){
            throw std::string("打開資料庫失敗");
        }
    }
    query = new QSqlQuery(mydb);
    seatDao = new SeatDao(query);
    menuDao = new MenuDao(query);

    _rmsHandler = new RMSHandler(seatDao,menuDao);
    lg = new LoginPage(this,_rmsHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCustomer_clicked()
{
    this->hide();
    //this->close();
    lg->exec();
}

void MainWindow::on_btnStaff_clicked()
{
    StaffManage * sm = new StaffManage(nullptr, _rmsHandler);
    this->hide();
    sm->show();
}

void MainWindow::on_btnBoss_clicked(){

}
