#include <QCoreApplication>
#include <QDebug>

#include "mymath.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyMath math;
    int data = math.calculate(10, 20);
    qInfo() << "data=" << data;

    return a.exec();
}
