#include "cannon.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cannon w;
    w.show();
    return a.exec();
}
