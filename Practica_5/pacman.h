#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include "laberinto.h"

class Pacman : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    Pacman();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void mover(int key, Laberinto *lab, QGraphicsScene *scene);
    void setLaberintoYEscena(Laberinto *l, QGraphicsScene *s);
public slots:
    void moverAuto();
    void animarBoca();

private:
    int paso = 25;
    int direccion = 0;
    Qt::Key ultimaTecla;
    bool bocaAbierta = true;
    QTimer *timerMovimiento;
    QTimer *timerBoca;
    Laberinto *labRef;
    QGraphicsScene *sceneRef;
};

#endif // PACMAN_H
