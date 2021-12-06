#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{
}

Worker::~Worker() {
    qDebug() << Q_FUNC_INFO;
}


void Worker::doWork() {
    qDebug() << Q_FUNC_INFO;
    emit finished();
}

