// simulador.h
#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QGraphicsScene>
#include <QTimer>
#include "cuerpo.h"

class Simulador : public QGraphicsScene {
    Q_OBJECT

public:
    Simulador(QObject* parent = nullptr);
    void iniciarSistema1();
    void iniciarSistema2();
    void agregarCuerpo(Cuerpo* cuerpo);
    void calcularFuerzas();
    void limpiarCuerpos();
    QVector<Cuerpo*> obtenerCuerpos()const;

private slots:
    void actualizar();

private:
    QVector<Cuerpo*> cuerpos;
    QTimer* timer;
    QVector<QGraphicsEllipseItem*> rastros;
    long long int contadorActualizaciones = 0;

};

#endif // SIMULADOR_H
