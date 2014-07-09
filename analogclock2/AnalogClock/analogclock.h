#pragma once

#include <QWidget>

/// Makes clock, which shows time
class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0);

    /// Checks if GMT on or not
    void GMTon (bool checkGMT);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool mCheckGMT = false;
};
