#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>
#include <QTime>


class Ball: public QGraphicsItem
{
public:
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget) override;
     Ball();
     void speedChange (int speedchange);
     void startChange (bool startchange);
     void angleChange (double anglechange);
     double XBall();
     double YBall();
     void stopBall();

private:
    int mSpeed = 0;
    bool mStart = false;
    double mAngle = 0;
    QTime time = QTime();
    double mXBall = 0, mYBall = 0;
};

