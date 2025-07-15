#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsEllipseItem>
#include <QVector2D>

class Cuerpo : public QGraphicsEllipseItem {
public:
    Cuerpo(double masa, double radio, QVector2D posicion, QVector2D velocidad, QColor color = Qt::cyan);

    void aplicarFuerza(const QVector2D& f);
    void reiniciarFuerza();
    void actualizar(double dt);

    // Getters
    double getMasa() const;
    double getRadio() const;
    QVector2D getPosicion() const;
    QVector2D getVelocidad() const;

    // Setters
    void setMasa(double m);
    void setRadio(double r);
    void setPosicion(QVector2D p);
    void setVelocidad(QVector2D v);

private:
    double masa;
    double radio;
    QVector2D posicion;
    QVector2D velocidad;
    QVector2D fuerza;

    void actualizarGrafico();
};

#endif // CUERPO_H

