#include "pacman.h"
#include "fantasma.h"
#include <QPainter>


// Constructor de la clase Pacman
Pacman::Pacman() {
    setFlag(QGraphicsItem::ItemIsFocusable); // Permite que Pacman reciba eventos de teclado
    setFocus(); // Le da el foco de entrada a Pacman

    // Timer para el movimiento automático
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Pacman::moverAuto);
    timerMovimiento->start(150);

    // Timer para animar la boca (abrir/cerrar)
    timerBoca = new QTimer(this);
    connect(timerBoca, &QTimer::timeout, this, &Pacman::animarBoca);
    timerBoca->start(100);
}

// Método para guardar referencias al laberinto y la escena
void Pacman::setLaberintoYEscena(Laberinto *l, QGraphicsScene *s) {
    labRef = l;
    sceneRef = s;
}

// Alterna el estado de la boca (abierta ↔ cerrada) y actualiza el dibujo
void Pacman::animarBoca() {
    bocaAbierta = !bocaAbierta;
}

// Llama al método de mover con la dirección actual para moverse automáticamente
void Pacman::moverAuto() {
    mover(ultimaTecla, labRef, sceneRef);
}

// Devuelve el área que ocupa Pacman
QRectF Pacman::boundingRect() const {
    return QRectF(0, 0, paso, paso);
}

// Dibuja a Pacman en pantalla: si la boca está abierta, lo dibuja como "pie", si no, como círculo
void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::yellow);
    if (bocaAbierta) {
        int angulos[4] = {30, 300, 210, 120};
        int startAngle = angulos[direccion];
        painter->drawPie(boundingRect(), startAngle * 16, 300 * 16);
    } else {
        painter->drawEllipse(boundingRect());
    }
}

// Lógica de movimiento y colisiones
void Pacman::mover(int key, Laberinto *lab, QGraphicsScene *scene) {
    QPointF nueva = pos();
    // Cambia la posición y la dirección según la tecla
    if (key == Qt::Key_D) {
        nueva.setX(nueva.x() + paso);
        direccion = 0;
        ultimaTecla = Qt::Key_D;
    } else if (key == Qt::Key_Z) {
        nueva.setY(nueva.y() + paso);
        direccion = 1;
        ultimaTecla = Qt::Key_Z;
    } else if (key == Qt::Key_A) {
        nueva.setX(nueva.x() - paso);
        direccion = 2;
        ultimaTecla = Qt::Key_A;
    } else if (key == Qt::Key_S) {
        nueva.setY(nueva.y() - paso);
        direccion = 3;
        ultimaTecla = Qt::Key_S;
    } else {
        return; // Tecla no válida, no hacer nada
    }

    // Solo se mueve si no hay una pared en la nueva posición
    if (!lab->esPared(nueva)) {
        QList<QGraphicsItem*> items = scene->items(QRectF(nueva, QSizeF(paso, paso)));
            // Verifica los objetos con los que colisiona en la nueva casilla
        for (QGraphicsItem *item : items) {
            // Si es un punto de poder, vuelve vulnerables a todos los fantasmas
            if (item->data(0) == "punto") {
                scene->removeItem(item);
                delete item;
            } else if (item->data(0) == "poder") {
                scene->removeItem(item);
                delete item;
                QList<QGraphicsItem*> todos = scene->items();
                for (auto i : todos) {
                    Fantasma *f = dynamic_cast<Fantasma*>(i);
                    if (f) f->setVulnerable(true);
                }
                // Si choca con un fantasma
            } else if (Fantasma *f = dynamic_cast<Fantasma*>(item)) {
                if (f->esVulnerable()) {
                    scene->removeItem(f);
                    delete f;
                } else {
                    // Si no es vulnerable, Pacman pierde y vuelve al inicio
                    setPos(25, 25);
                    return;
                }
            }
        }
        // Si no hay problema, se mueve a la nueva posición
        setPos(nueva);
    }
}
