#include "laberinto.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

// Constructor de la clase Laberinto
Laberinto::Laberinto() {
    mapa << "############################"
         << "#............##............#"
         << "#.####.#####.##.#####.####.#"
         << "#.####.#   #.##.#   #.####.#"
         << "#.####.#####.##.#####.####.#"
         << "#............  ............#"
         << "#.####.##.########.##.####.#"
         << "#..........................#"
         << "######.##### ## #####.######"
         << "#............##............#"
         << "#.####.#####.##.#####.####.#"
         << "#.####.#####.##.#####.####.#"
         << "#.####.#####.##.#####.####.#"
         << "#............##............#"
         << "############################";
}

// Método para generar gráficamente el laberinto en la escena
void Laberinto::generar(QGraphicsScene *scene) {
    for (int y = 0; y < mapa.size(); ++y) {
        for (int x = 0; x < mapa[y].length(); ++x) {
            QChar c = mapa[y][x];
            if (c == '#') {
                scene->addRect(x * 25, y * 25, 25, 25, QPen(Qt::black), QBrush(Qt::darkBlue));
            } else if (c == '.') {
                QGraphicsEllipseItem *punto = scene->addEllipse(x * 25 + 10, y * 25 + 10, 5, 5, QPen(), QBrush(Qt::white));
                punto->setData(0, "punto");
            }
        }
    }
}


// Método que verifica si una posición (x, y) es una pared
bool Laberinto::esPared(const QPointF &pos) {
    int x = int(pos.x()) / 25;
    int y = int(pos.y()) / 25;
    if (y < 0 || y >= mapa.size() || x < 0 || x >= mapa[y].size()) return true;
    return mapa[y][x] == '#';
}
