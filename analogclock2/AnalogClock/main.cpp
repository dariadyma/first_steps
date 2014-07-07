#include "mainwindow.h"
#include "analogclock.h"
#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;



 #if defined(Q_OS_SYMBIAN)
    w.showMaximized();
 #else
    w.show();
 #endif
    return a.exec();
}
