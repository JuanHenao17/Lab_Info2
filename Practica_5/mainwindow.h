#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "pacman.h"
#include "laberinto.h"

class MainWindow : public QGraphicsView {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    QGraphicsScene *scene;
    Pacman *pacman;
    Laberinto *laberinto;
};

#endif // MAINWINDOW_H
