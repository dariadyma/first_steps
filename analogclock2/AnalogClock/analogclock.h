#ifndef ANALOGCLOCK_H
 #define ANALOGCLOCK_H

 #include <QWidget>

 class AnalogClock : public QWidget
 {
     Q_OBJECT

 public:
     AnalogClock(QWidget *parent = 0);
     void GMT_on (bool checkGMT);

 protected:
     void paintEvent(QPaintEvent *event);

private:
     bool checkGMT = false;
 };

 #endif



