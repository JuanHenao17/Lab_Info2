#include "simulador.h"
#include <cmath>
#include <QPushButton>
#include <QAbstractButton>

const double G = 1.0;
const double dt = 1.0;

Simulador::Simulador(QObject* parent) : QGraphicsScene(parent) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulador::actualizar);
}

void Simulador::iniciarSistema1() {
    limpiarCuerpos();

    cuerpos.append(new Cuerpo(70, 120, QVector2D(0, -7000), QVector2D(2, 0), Qt::darkBlue));
    cuerpos.append(new Cuerpo(70000, 300, QVector2D(0, 0), QVector2D(0, 0), Qt::black));
    cuerpos.append(new Cuerpo(25, 100, QVector2D(4000, 5000), QVector2D(-1.6, 1.2), Qt::darkGreen));

    for (Cuerpo* c : cuerpos)
        addItem(c);

    timer->start(16);

}

QVector<Cuerpo*> Simulador::obtenerCuerpos() const { return cuerpos; }

void Simulador::iniciarSistema2() {
    limpiarCuerpos();

    cuerpos.append(new Cuerpo(50000, 200, QVector2D(0, 0), QVector2D(0, 0)));
    cuerpos.append(new Cuerpo(70, 70, QVector2D(-5000, 0), QVector2D(0, -2),Qt::black));
    cuerpos.append(new Cuerpo(70, 70, QVector2D(5000, 0), QVector2D(0, 2),Qt::red));
    cuerpos.append(new Cuerpo(70, 70, QVector2D(0, -5000), QVector2D(2, 0),Qt::darkBlue));
    cuerpos.append(new Cuerpo(70, 70, QVector2D(0, 5000), QVector2D(-2, 0),Qt::green));

    for (Cuerpo* c : cuerpos)
        addItem(c);

    timer->start(16);
}

void Simulador::calcularFuerzas() {
    for (Cuerpo* c : cuerpos)
        c->reiniciarFuerza();

    for (int i = 0; i < cuerpos.size(); ++i) {
        for (int j = i + 1; j < cuerpos.size(); ++j) {
            Cuerpo* a = cuerpos[i];
            Cuerpo* b = cuerpos[j];

            QVector2D r = b->getPosicion() - a->getPosicion();
            double dist2 = r.lengthSquared();
            double fuerzaMag = G * a->getMasa() * b->getMasa() / dist2;
            QVector2D fuerza = fuerzaMag * r.normalized();

            a->aplicarFuerza(fuerza);
            b->aplicarFuerza(-fuerza);
        }
    }
}

void Simulador::actualizar() {
    calcularFuerzas();
    contadorActualizaciones++;

    for (Cuerpo* c : cuerpos)
        c->actualizar(dt);

    // Solo dejar rastro cada 5 ciclos, por ejemplo
    if (contadorActualizaciones % 20 == 0) {
        for (Cuerpo* c : cuerpos) {
            auto trazo = new QGraphicsEllipseItem(-1, -1, 2, 2);
            trazo->setPos(c->getPosicion().x() * 0.05, -c->getPosicion().y() * 0.05);
            trazo->setBrush(c->brush());
            trazo->setPen(Qt::NoPen);
            addItem(trazo);
            rastros.append(trazo);
        }
    }
}

void Simulador::limpiarCuerpos() {
    timer->stop();

    // Eliminar cuerpos
    for (Cuerpo* c : cuerpos) {
        removeItem(c);
        delete c;
    }
    cuerpos.clear();

    // Eliminar rastros
    for (QGraphicsEllipseItem* r : rastros) {
        removeItem(r);
        delete r;
    }
    rastros.clear();

    contadorActualizaciones = 0;
}
