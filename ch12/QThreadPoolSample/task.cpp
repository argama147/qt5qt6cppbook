#include "task.h"

#include <QDebug>
#include <QThread>

Task::Task(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__;
}

Task::~Task()
{
    qDebug() << __FUNCTION__;
}

void Task::run()
{
    work();
}

void Task::work()
{
    qInfo() << metaObject()->className() << ":"
            << __FUNCTION__ << QThread::currentThread();
}
