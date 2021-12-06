#include <QCoreApplication>
#include <QDebug>
#include "worker.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker* worker = new Worker(&a);
    worker->work("2");
    worker->work("a");

    return a.exec();
}
