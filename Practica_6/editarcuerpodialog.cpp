#include "editarcuerpodialog.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

EditarCuerpoDialog::EditarCuerpoDialog(const QVector<Cuerpo*>& cuerpos, QWidget *parent)
    : QDialog(parent), cuerpos(cuerpos)
{
    setWindowTitle("Editar Cuerpo");

    selector = new QComboBox;
    for (int i = 0; i < cuerpos.size(); ++i) {
        selector->addItem("Cuerpo " + QString::number(i + 1));
    }

    spnMasa = new QDoubleSpinBox(); spnMasa->setRange(0.1, 1e6);
    spnRadio = new QDoubleSpinBox(); spnRadio->setRange(1, 500);
    spnPosX = new QDoubleSpinBox(); spnPosX->setRange(-1e5, 1e5);
    spnPosY = new QDoubleSpinBox(); spnPosY->setRange(-1e5, 1e5);
    spnVelX = new QDoubleSpinBox(); spnVelX->setRange(-1000, 1000);
    spnVelY = new QDoubleSpinBox(); spnVelY->setRange(-1000, 1000);

    btnAplicar = new QPushButton("Aplicar cambios");

    QFormLayout* form = new QFormLayout;
    form->addRow("Seleccionar cuerpo:", selector);
    form->addRow("Masa:", spnMasa);
    form->addRow("Radio:", spnRadio);
    form->addRow("Posición X:", spnPosX);
    form->addRow("Posición Y:", spnPosY);
    form->addRow("Velocidad X:", spnVelX);
    form->addRow("Velocidad Y:", spnVelY);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(btnAplicar);

    connect(selector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EditarCuerpoDialog::cargarDatosCuerpo);
    connect(btnAplicar, &QPushButton::clicked, this, &EditarCuerpoDialog::aplicarCambios);

    cargarDatosCuerpo(0); // inicializar con el primer cuerpo
}

void EditarCuerpoDialog::cargarDatosCuerpo(int index) {
    if (index >= 0 && index < cuerpos.size()) {
        Cuerpo* c = cuerpos[index];
        spnMasa->setValue(c->getMasa());
        spnRadio->setValue(c->getRadio());
        spnPosX->setValue(c->getPosicion().x());
        spnPosY->setValue(c->getPosicion().y());
        spnVelX->setValue(c->getVelocidad().x());
        spnVelY->setValue(c->getVelocidad().y());
    }
}

void EditarCuerpoDialog::aplicarCambios() {
    int index = selector->currentIndex();
    if (index >= 0 && index < cuerpos.size()) {
        Cuerpo* c = cuerpos[index];
        c->setMasa(spnMasa->value());
        c->setRadio(spnRadio->value());
        c->setPosicion(QVector2D(spnPosX->value(), spnPosY->value()));
        c->setVelocidad(QVector2D(spnVelX->value(), spnVelY->value()));
    }
}
