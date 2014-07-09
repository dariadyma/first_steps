#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>

class Gun: public QGraphicsItem
{
public:
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget) override;
     void angleChange (double anglechange);

private:
    double mAngle = 0;
};

