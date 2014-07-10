#include <QtCore/QTime>
#include <QtCore/QTimer>

#include "ball.h"

Ball::Ball()
{
	mTime = QTime{0, 0, 0, 0};
}

QRectF Ball::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth / 2, 20 + penWidth / 2);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	if (mTime != QTime{0, 0, 0, 0})
	{
		double xSpeed = mSpeed * cos(mAngle / 180 * 3.14);
		double ySpeed = mSpeed * sin(mAngle / 180 * 3.14);
		double t = mTime.elapsed();

		mXBall = 75 + 70 * cos(mAngle / 180 * 3.14) + xSpeed * t / 100.0;
		mYBall = 330 - 70 * sin(mAngle / 180 * 3.14) - ySpeed *  t / 100.0 + (t * t) * 0.2 / 10000.0;

		painter->setTransform(QTransform());
		painter->setBrush(Qt::blue);
		painter->drawEllipse(QPointF{mXBall, mYBall}, 5, 5);
	}
}

void Ball::speedChange(int speed)
{
	mSpeed = speed;
}

void Ball::startChange(bool start)
{
	mStart = start;
	mTime.start();
}

void Ball::stopBall()
{
	mTime = QTime{0, 0, 0, 0};
}

void Ball::angleChange(double angle)
{
	mAngle = angle;
}

double Ball::xBall() const
{
	return mXBall;
}

double Ball::yBall() const
{
	return mYBall;
}
