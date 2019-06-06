#include "host_dialog.h"
#include "ui_hostdialog.h"
#include "staff_manage.h"

HostDialog::HostDialog(QWidget *parent, RMSHandler * rmsHandler) :
    QDialog(parent),
    ui(new Ui::HostDialog),
    _rmsHandler(rmsHandler)
{
    ui->setupUi(this);
    QString IP;
    quint16 port;
    _rmsHandler->SetNewConnectionListener(this, SLOT(onNewConnection()));
    _rmsHandler->Host(IP,port);
    ui->ip->setText(IP);
    ui->port->setText(QString::number(port));
}

HostDialog::~HostDialog()
{
    delete ui;
}

void HostDialog::onNewConnection(){
    StaffManage * staffManage = new StaffManage(nullptr, _rmsHandler);
    this->close();
    staffManage ->show();
    _rmsHandler->closeDB();
}
