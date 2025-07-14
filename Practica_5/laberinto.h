#ifndef LABERINTO_H
#define LABERINTO_H

#include <QGraphicsScene>
#include <QStringList>

class Laberinto {
public:
    Laberinto();
    void generar(QGraphicsScene *scene);
    bool esPared(const QPointF &pos);
private:
    QStringList mapa;
};

#endif // LABERINTO_H
