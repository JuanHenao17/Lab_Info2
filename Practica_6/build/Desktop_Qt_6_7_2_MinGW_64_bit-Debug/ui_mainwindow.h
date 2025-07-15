/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnSistema1;
    QPushButton *btnSistema2;
    QPushButton *btnSalir;
    QPushButton *btnVolver;
    QGraphicsView *vistaSimulacion;
    QPushButton *btnEditar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnSistema1 = new QPushButton(centralwidget);
        btnSistema1->setObjectName("btnSistema1");
        btnSistema1->setGeometry(QRect(280, 250, 231, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Snap ITC")});
        font.setPointSize(16);
        btnSistema1->setFont(font);
        btnSistema2 = new QPushButton(centralwidget);
        btnSistema2->setObjectName("btnSistema2");
        btnSistema2->setGeometry(QRect(600, 250, 251, 71));
        btnSistema2->setFont(font);
        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setGeometry(QRect(480, 390, 161, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Snap ITC")});
        font1.setPointSize(10);
        btnSalir->setFont(font1);
        btnVolver = new QPushButton(centralwidget);
        btnVolver->setObjectName("btnVolver");
        btnVolver->setGeometry(QRect(30, 778, 191, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Snap ITC")});
        font2.setPointSize(11);
        btnVolver->setFont(font2);
        vistaSimulacion = new QGraphicsView(centralwidget);
        vistaSimulacion->setObjectName("vistaSimulacion");
        vistaSimulacion->setGeometry(QRect(0, 0, 1200, 900));
        btnEditar = new QPushButton(centralwidget);
        btnEditar->setObjectName("btnEditar");
        btnEditar->setGeometry(QRect(250, 778, 171, 51));
        btnEditar->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        vistaSimulacion->raise();
        btnSistema1->raise();
        btnSistema2->raise();
        btnSalir->raise();
        btnVolver->raise();
        btnEditar->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSistema1->setText(QCoreApplication::translate("MainWindow", "Sistema 1", nullptr));
        btnSistema2->setText(QCoreApplication::translate("MainWindow", "Sistema 2", nullptr));
        btnSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        btnVolver->setText(QCoreApplication::translate("MainWindow", "Volver al Men\303\272", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar Cuerpo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
