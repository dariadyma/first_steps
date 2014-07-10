#include <QtCore/QTimer>

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

	mScen->addItem(mGun);
	mScen->addItem(mBall);
	mScen->addItem(mTarget);
	mUi->graphicsView->setScene(mScen);

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Cannon::scenUpDate);
	timer->start(10);
}

void Cannon::scenUpDate()
{
	 mScen->update() ;

	 if ((mBall->xBall() ) <= (mTarget->xTarget() + 20)
			 && (mBall->xBall() + 5 ) >= (mTarget->xTarget() - 20)
			 && (mBall->yBall() ) <= (mTarget->yTarget() + 20)
			 && (mBall->yBall() + 5 ) >= (mTarget->yTarget() - 20))
	 {
		mUi->label_3->setText("YOU WIN!");
		mBall->stopBall();
		mTarget->stopTarget();
		mTarget->speedChange(1);
	 }

	 if ((mTarget->xTarget() + 20) >= 820)
	 {
		 mUi->label_3->setText("YOU LOSE!");
		 mTarget->stopTarget();
		 mTarget->speedChange(-1);
	 }
}

void Cannon::angleChange()
{
	mGun->angleChange(mUi->Angl->value());
	mBall->angleChange(mUi->Angl->value());
	mScen->update() ;
}

void Cannon::speedChange()
{
	mBall->speedChange(mUi->Speed->value());
}

void Cannon::startChange()
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
	delete mScen;
}
