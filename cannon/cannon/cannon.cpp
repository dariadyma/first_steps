#include "cannon.h"
#include "ui_cannon.h"
#include <QTimer>

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
    scen->addItem(mBall);
    scen->addItem(mTarget);
    mUi->graphicsView->setScene(scen);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cannon::scenUpDate);
    timer->start(10);
}

void Cannon::scenUpDate ()
{
     scen->update() ;
     if ((mBall->XBall() ) <= (mTarget->XTarget() + 20) &&
             (mBall->XBall() + 5 ) >= (mTarget->XTarget() - 20) &&
             (mBall->YBall() ) <= (mTarget->YTarget() + 20) &&
             (mBall->YBall() + 5 ) >= (mTarget->YTarget() - 20) )
     {
        mUi->label_3->setText("YOU WIN!");
        mBall->stopBall();
        mTarget->stopTarget();
        mTarget->speedChange(1);

     }
     if ((mTarget->XTarget() + 20) >= 820)
     {
         mUi->label_3->setText("YOU LOSE!");
         mTarget->stopTarget();
         mTarget->speedChange(-1);
     }

}

void Cannon::angleChange ()
{
    mGun->angleChange(mUi->Angl->value());
    mBall->angleChange(mUi->Angl->value());
    scen->update() ;
}

void Cannon::speedChange ()
{
    mBall->speedChange(mUi->Speed->value());
}

void Cannon::startChange ()
{
    mBall->startChange(mUi->pushButton->isFlat());
    mUi->label_3->setText("");
}

Cannon::~Cannon()
{
    delete mUi;
    delete mGun;
    delete mTarget;
    delete mBall;
    delete scen;
}
