#include "gun.h"

QRectF Gun::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth / 2, 20 + penWidth / 2);
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	painter->setTransform(QTransform());
	painter->save();
	painter->fillRect(10, 320, 70, 50, Qt::gray);
	painter->setTransform(QTransform().translate(70, 325).rotate(- mAngle));
	painter->setBrush(Qt::red);
	painter->drawRect(0, 0, 70, 10);
	painter->restore();
}


void Gun::angleChange (double angle)
{
	mAngle = angle;
}

















