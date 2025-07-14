#ifndef FANTASMA_H
#define FANTASMA_H

#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QColor>
#include "laberinto.h"

class Fantasma : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Fantasma(QColor color, Laberinto *lab);
    void mover();
    void setVulnerable(bool vulnerable);
    bool esVulnerable() const;

private:
    Laberinto *laberinto;
    QTimer *timer;
    int paso = 25;
    bool vulnerable = false;
    QColor colorNormal;
};

#endif // FANTASMA_H
