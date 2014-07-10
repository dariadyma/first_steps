#include "ball.h"

#include <QTcore>
#include <QTgui>
#include <QTime>
#include <QTimer>

QRectF Ball::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth / 2, 20 + penWidth / 2);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (time != QTime{0, 0, 0, 0})
    {
        double xSpeed = mSpeed * cos(mAngle/180*3.14), ySpeed = mSpeed * sin(mAngle/180*3.14);
        double t = time.elapsed();

        mXBall = 75 + 70 * cos(mAngle/180*3.14) + xSpeed * t / 100.0;
        mYBall = 330 - 70 * sin(mAngle/180*3.14) - ySpeed *  t / 100.0 + (t * t) * 0.2 / 10000.0;

        painter->setTransform(QTransform());
        painter->setBrush(Qt::blue);
        painter->drawEllipse(QPointF{mXBall, mYBall}, 5, 5);
    }
}

Ball::Ball()
{
    time = QTime{0, 0, 0, 0};
}


void Ball::speedChange (int speedchange)
{
    mSpeed = speedchange;
}

void Ball::startChange (bool startchange)
{
    mStart = startchange;
    time.start();

}

void Ball::stopBall()
{
    time = QTime{0, 0, 0, 0};
}

void Ball::angleChange (double anglechange)
{
    mAngle = anglechange;
}

double Ball::XBall()
{
    return mXBall;
}

double Ball::YBall()
{
    return mYBall;
}
