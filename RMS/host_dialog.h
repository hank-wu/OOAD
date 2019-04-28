#ifndef HOST_DIALOG_H
#define HOST_DIALOG_H

#include <QDialog>
#include "rmshandler.h"
#include "staff_manage.h"

namespace Ui {
class HostDialog;
}

class HostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HostDialog(QWidget *parent, RMSHandler * rmsHandler);
    ~HostDialog();

private:
    Ui::HostDialog *ui;
    RMSHandler * _rmsHandler;
private slots:
    void onNewConnection();
};

#endif // HOST_DIALOG_H
