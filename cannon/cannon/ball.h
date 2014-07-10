#pragma once

#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtGUI/QPainter>
#include <iostream>
#include <QtCore/QTime>

class Ball: public QGraphicsItem
{
public:
	 Ball();
	 QRectF boundingRect() const override;
	 void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	 /// Change speed of ball.
	 void speedChange (int speed);

	 /// Button was pressed so ball start moving.
	 void startChange (bool start);

	 /// Stop the ball.
	 void stopBall();

	 /// Cause of changing angle of gun the begin position of ball changes.
	 void angleChange (double angle);

	 /// Returns x-coordinate of ball.
	 double xBall() const;

	 /// Returns y-coordinate of ball.
	 double yBall() const;

private:
	int mSpeed = 0;
	bool mStart = false;
	double mAngle = 0;
	QTime mTime = QTime();
	double mXBall = 0;
	double mYBall = 0;
};

