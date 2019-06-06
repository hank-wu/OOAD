/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnBoss;
    QPushButton *btnStaff;
    QPushButton *btnCustomer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(558, 380);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnBoss = new QPushButton(centralWidget);
        btnBoss->setObjectName(QString::fromUtf8("btnBoss"));
        btnBoss->setGeometry(QRect(360, 60, 121, 191));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(20);
        btnBoss->setFont(font);
        btnStaff = new QPushButton(centralWidget);
        btnStaff->setObjectName(QString::fromUtf8("btnStaff"));
        btnStaff->setGeometry(QRect(210, 60, 121, 191));
        btnStaff->setFont(font);
        btnCustomer = new QPushButton(centralWidget);
        btnCustomer->setObjectName(QString::fromUtf8("btnCustomer"));
        btnCustomer->setGeometry(QRect(50, 60, 131, 191));
        btnCustomer->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 558, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\201\270\346\223\207\344\275\277\347\224\250\350\200\205", nullptr));
        btnBoss->setText(QApplication::translate("MainWindow", "Boss", nullptr));
        btnStaff->setText(QApplication::translate("MainWindow", "Staff", nullptr));
        btnCustomer->setText(QApplication::translate("MainWindow", "Customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
