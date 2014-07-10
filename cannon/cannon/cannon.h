#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>


#include "gun.h"
#include "ball.h"
#include "target.h"

namespace Ui {
class Cannon;
}

class Cannon : public QMainWindow
{
	Q_OBJECT

public:
	explicit Cannon(QWidget *parent = 0);
	~Cannon();

	/// say to ball and gun that angle was changed
	void angleChange();

	/// say to ball that speed was changed
	void speedChange();

	/// say to ball and target that button start was pressed
	void startChange();

	/// updates scene, write win or lose
	void scenUpDate ();

private:
	Ui::Cannon *mUi;
	Gun *mGun = new Gun();
	Ball *mBall = new Ball();
	Target *mTarget = new Target ();
	QGraphicsScene *mScen = new QGraphicsScene();
	double mAngle = 0;
};

