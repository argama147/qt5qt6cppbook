#include <QCoreApplication>
#include <QThreadPool>
#include <QDebug>

#include "task.h"

void work() {
    qInfo() << __FUNCTION__ << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "maxThreadCount"
            << QThreadPool::globalInstance()->maxThreadCount();

    QThreadPool::globalInstance()->start(work);


    Task* task = new Task();
    task->setAutoDelete(true);
    QThreadPool::globalInstance()->start(task);

    return a.exec();
}
