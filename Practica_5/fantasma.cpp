#include "fantasma.h"
#include <QBrush>
#include <QRandomGenerator>

// Constructor del fantasma
Fantasma::Fantasma(QColor color, Laberinto *lab) : laberinto(lab), colorNormal(color) {
    setRect(0, 0, paso, paso);
    setBrush(color);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Fantasma::mover);
    timer->start(300);
}

// Método que define el movimiento aleatorio del fantasma
void Fantasma::mover() {
    QList<QPointF> direcciones = {
        pos() + QPointF(paso, 0),
        pos() + QPointF(-paso, 0),
        pos() + QPointF(0, paso),
        pos() + QPointF(0, -paso)
    };
    // Mezcla las direcciones aleatoriamente
    std::shuffle(direcciones.begin(), direcciones.end(), *QRandomGenerator::global());
    // Intenta moverse a la primera dirección válida (no es pared)
    for (const QPointF &nueva : direcciones) {
        if (!laberinto->esPared(nueva)) {
            setPos(nueva);
            break;
        }
    }
}

// Establece el estado vulnerable del fantasma y cambia su color si es necesario
void Fantasma::setVulnerable(bool state) {
    vulnerable = state;
    setBrush(state ? Qt::blue : colorNormal);
}


// Devuelve si el fantasma es vulnerable o no (para que Pacman pueda comérselo)
bool Fantasma::esVulnerable() const {
    return vulnerable;
}
