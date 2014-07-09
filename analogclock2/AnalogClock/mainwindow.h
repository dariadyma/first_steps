#pragma once

#include <QMainWindow>
#include "analogclock.h"

namespace Ui {
class MainWindow;
}

/// Parent class for clocks and it contains GMT button
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;

public slots:

    /// Check changes on button GMT
    void changeGMT();

private:
    Ui::MainWindow *mUi;
    AnalogClock *mClock = new AnalogClock(this);
};
