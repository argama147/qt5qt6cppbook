#include "task.h"

#include <QDebug>
#include <QThread>

Task::Task(QObject *parent) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;
}

Task::~Task()
{
    qDebug() << Q_FUNC_INFO;
}

void Task::run()
{
    work();
}

void Task::work()
{
    qInfo() << metaObject()->className() << ":"
            << Q_FUNC_INFO << QThread::currentThread();
}
