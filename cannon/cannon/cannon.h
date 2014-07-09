#pragma once

#include "gun.h"
#include "ball.h"
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>

namespace Ui {
class Cannon;
}

class Cannon : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cannon(QWidget *parent = 0);
    ~Cannon();
    void angleChange();
    void speedChange();
    void startChange();

private:
    Ui::Cannon *mUi;
    Gun *mGun = new Gun();
    Ball *mBall = new Ball();
    QGraphicsScene *scen = new QGraphicsScene();
    double mAngle = 0;

};

