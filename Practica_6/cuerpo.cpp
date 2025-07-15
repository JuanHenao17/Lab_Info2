#include "cuerpo.h"
#include <QBrush>
#include <QPen>

const double ESCALA = 0.05;

Cuerpo::Cuerpo(double masa, double radio, QVector2D posicion, QVector2D velocidad, QColor color)
    : masa(masa), radio(radio), posicion(posicion), velocidad(velocidad), fuerza(0, 0)
{
    setRect(-radio * ESCALA, -radio * ESCALA, 2 * radio * ESCALA, 2 * radio * ESCALA);
    setBrush(QBrush(color));
    setPen(Qt::NoPen);
    actualizarGrafico();
}

void Cuerpo::aplicarFuerza(const QVector2D& f) { fuerza += f; }
void Cuerpo::reiniciarFuerza() { fuerza = QVector2D(0, 0); }

void Cuerpo::actualizar(double dt) {
    QVector2D aceleracion = fuerza / masa;
    velocidad += aceleracion * dt;
    posicion += velocidad * dt;
    actualizarGrafico();
}

void Cuerpo::actualizarGrafico() {
    setPos(posicion.x() * ESCALA, -posicion.y() * ESCALA);
}

double Cuerpo::getMasa() const { return masa; }
double Cuerpo::getRadio() const { return radio; }
QVector2D Cuerpo::getPosicion() const { return posicion; }
QVector2D Cuerpo::getVelocidad() const { return velocidad; }

void Cuerpo::setMasa(double m) { masa = m; }
void Cuerpo::setRadio(double r) {
    radio = r;
    setRect(-radio * ESCALA, -radio * ESCALA, 2 * radio * ESCALA, 2 * radio * ESCALA);
}
void Cuerpo::setPosicion(QVector2D p) { posicion = p; actualizarGrafico(); }
void Cuerpo::setVelocidad(QVector2D v) { velocidad = v; }
