#include "cannon.h"
#include "ui_cannon.h"

Cannon::Cannon(QWidget *parent) :
    QMainWindow(parent),
    mUi(new Ui::Cannon)
{
    mUi->setupUi(this);

    QObject::connect(mUi->Angl, static_cast<void (QDoubleSpinBox:: *)(double)>(
                     &QDoubleSpinBox::valueChanged), this, &Cannon::angleChange);
    QObject::connect(mUi->Speed, static_cast<void (QSpinBox:: *)(int)>(
                     &QSpinBox::valueChanged), this, &Cannon::speedChange);
    QObject::connect(mUi->pushButton, &QPushButton::clicked, this, &Cannon::startChange);

    scen->addItem(mGun);
    mUi->graphicsView->setScene(scen);
}

void Cannon::angleChange ()
{
    mGun->angleChange(mUi->Angl->value());
    scen->update() ;
}

void Cannon::speedChange ()
{
    mBall->speedChange(mUi->Speed->value());
}

void Cannon::startChange ()
{
    mBall->startChange(mUi->pushButton->isFlat());
}

Cannon::~Cannon()
{
    delete mUi;
}
