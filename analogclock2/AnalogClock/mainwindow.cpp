#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analogclock.h"

#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUi(new Ui::MainWindow)
{
    mUi->setupUi(this);
    QObject::connect(mUi->checkBox, &QCheckBox::clicked, this, &MainWindow::changeGMT);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mClock);
    layout->addWidget(mUi->checkBox);
    this->centralWidget()->setLayout(layout);
}


void MainWindow::changeGMT()
{
    mClock->GMTon(mUi->checkBox->isChecked());
}

MainWindow::~MainWindow()
{
    delete mUi;
}


