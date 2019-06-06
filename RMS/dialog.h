#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "rmshandler.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent, RMSHandler * rmsHandler);
    ~Dialog();

signals:
    void success();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_okButton_clicked();

private:
    Ui::Dialog *ui;
    RMSHandler * _rmsHandler;
};

#endif // DIALOG_H
