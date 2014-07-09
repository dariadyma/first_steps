#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>

class Ball: public QGraphicsItem
{
public:
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget) override;
     void speedChange (int speedchange);
     void startChange (bool startchange);

private:
    int mSpeed = 0;
    bool mStart = false;
};

