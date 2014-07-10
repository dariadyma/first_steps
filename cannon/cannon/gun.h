#pragma once

#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtGUI/QPainter>
#include <iostream>

class Gun: public QGraphicsItem
{
public:
	 QRectF boundingRect() const override;
	 void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	 void angleChange (double angle);

private:
	double mAngle = 0;
};

