#ifndef EDITARCUERPODIALOG_H
#define EDITARCUERPODIALOG_H

#include <QDialog>
#include <QVector>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include "cuerpo.h"

class EditarCuerpoDialog : public QDialog {
    Q_OBJECT

public:
    EditarCuerpoDialog(const QVector<Cuerpo*>& cuerpos, QWidget *parent = nullptr);

private slots:
    void cargarDatosCuerpo(int index);
    void aplicarCambios();

private:
    QVector<Cuerpo*> cuerpos;

    QComboBox* selector;
    QDoubleSpinBox *spnMasa, *spnRadio, *spnPosX, *spnPosY, *spnVelX, *spnVelY;
    QPushButton* btnAplicar;
};

#endif // EDITARCUERPODIALOG_H
