#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "editarcuerpodialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escenaSimulador = nullptr;

    connect(ui->btnSistema1, &QPushButton::clicked, this, &MainWindow::iniciarSistema1);
    connect(ui->btnSistema2, &QPushButton::clicked, this, &MainWindow::iniciarSistema2);
    connect(ui->btnSalir, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(ui->btnVolver, &QPushButton::clicked, this, &MainWindow::volverAlMenu);
    connect(ui->btnEditar, &QPushButton::clicked, this, [this]() {
        if (escenaSimulador) {
            auto dialogo = new EditarCuerpoDialog(escenaSimulador->obtenerCuerpos(), this);
            dialogo->exec();
        }
    });

    // Solo se muestran botones del menú al inicio
    ui->vistaSimulacion->hide();
    ui->btnVolver->hide();
    ui->btnEditar->hide();
}

MainWindow::~MainWindow() {}

void MainWindow::iniciarSistema1() {
    escenaSimulador = new Simulador(this);
    escenaSimulador->iniciarSistema1();
    ui->vistaSimulacion->setScene(escenaSimulador);
    ui->vistaSimulacion->setRenderHint(QPainter::Antialiasing);
    ui->vistaSimulacion->setSceneRect(-600, -450, 1200, 900);
    ui->vistaSimulacion->fitInView(ui->vistaSimulacion->sceneRect(), Qt::KeepAspectRatio);

    // Mostrar simulación, ocultar menú
    ui->btnSistema1->hide();
    ui->btnSistema2->hide();
    ui->btnSalir->hide();
    ui->btnVolver->show();
    ui->btnEditar->show();
    ui->vistaSimulacion->show();
}

void MainWindow::iniciarSistema2() {
    escenaSimulador = new Simulador(this);
    escenaSimulador->iniciarSistema2();
    ui->vistaSimulacion->setScene(escenaSimulador);
    ui->vistaSimulacion->setRenderHint(QPainter::Antialiasing);
    ui->vistaSimulacion->setSceneRect(-600, -450, 1200, 900);
    ui->vistaSimulacion->fitInView(ui->vistaSimulacion->sceneRect(), Qt::KeepAspectRatio);

    // Mostrar simulación, ocultar menú
    ui->btnSistema1->hide();
    ui->btnSistema2->hide();
    ui->btnSalir->hide();
    ui->btnVolver->show();
    ui->btnEditar->show();
    ui->vistaSimulacion->show();
}

void MainWindow::volverAlMenu() {
    if (escenaSimulador) {
        delete escenaSimulador;
        escenaSimulador = nullptr;
    }

    // Ocultar elementos de simulación
    ui->vistaSimulacion->hide();
    ui->btnVolver->hide();
    ui->btnEditar->hide();

    // Mostrar menú principal
    ui->btnSistema1->show();
    ui->btnSistema2->show();
    ui->btnSalir->show();
}

