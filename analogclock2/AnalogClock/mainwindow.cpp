#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analogclock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::changeGMT);
}


void MainWindow::changeGMT()
{
    clock->GMT_on(ui->checkBox->isChecked());
}

MainWindow::~MainWindow()
{
    delete ui;
}


