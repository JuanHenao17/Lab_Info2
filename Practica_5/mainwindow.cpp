#include "mainwindow.h"
#include "fantasma.h"
#include <QGraphicsEllipseItem>

MainWindow::MainWindow(QWidget *parent) : QGraphicsView(parent) {
    // Crear una nueva escena donde se colocan todos los elementos gráficos
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Define el tamaño fijo de la ventana
    setFixedSize(750, 400);
    setSceneRect(0, 0, 750, 400);

    // Crear el laberinto y agregarlo a la escena
    laberinto = new Laberinto();
    laberinto->generar(scene);

    // Crear a Pac-Man, ubicarlo al inicio y agregarlo a la escena
    pacman = new Pacman();
    pacman->setPos(25, 25);
    scene->addItem(pacman);
    pacman->setLaberintoYEscena(laberinto, scene);

    // Añadir fantasmas
    Fantasma *rojo = new Fantasma(Qt::red, laberinto);
    rojo->setPos(375, 275);
    scene->addItem(rojo);

    Fantasma *rosa = new Fantasma(Qt::magenta, laberinto);
    rosa->setPos(400, 275);
    scene->addItem(rosa);

    // Puntos grandes para comer fantasmas
    QGraphicsEllipseItem *poder = scene->addEllipse(375 * 1 + 7, 200 * 1 + 7, 10, 10, QPen(), QBrush(Qt::green));
    poder->setData(0, "poder");
}

// Método que se ejecuta cuando se presiona una tecla
void MainWindow::keyPressEvent(QKeyEvent *event) {
    pacman->mover(event->key(), laberinto, scene);
}
