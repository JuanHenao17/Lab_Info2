#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    // Crea una instancia de la aplicación Qt, necesaria para cualquier programa con GUI
    QApplication app(argc, argv);
    // Crea una instancia de la clase MainWindow
    MainWindow w;
        // Muestra la ventana principal en pantalla
    w.show();
    // para crear el bucle del juego
    return app.exec();
}
