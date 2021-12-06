#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{
}

Worker::~Worker() {
    qDebug() << __FUNCTION__;
}


void Worker::doWork() {
    qDebug() << __FUNCTION__;
    emit finished();
}

