#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QPushButton>
#include "simulador.h" // donde estará la clase Simulador
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void iniciarSistema1();
    void iniciarSistema2();
    void volverAlMenu();

private:
    QWidget* contenedorMenu;
    QPushButton* btnSistema1;
    QPushButton* btnSistema2;
    QPushButton* btnSalir;

    QGraphicsView* vistaSimulacion;
    Simulador* escenaSimulador;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
