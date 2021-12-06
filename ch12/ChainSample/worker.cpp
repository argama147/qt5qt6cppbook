#include "worker.h"
#include "myexception.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent>


Worker::Worker(QObject *parent) : QObject(parent)
{

}

Worker::~Worker()
{
    qDebug() << __FUNCTION__;
}

void Worker::work(const QString &str)
{
    QFuture<int> future = QtConcurrent::run(convertStringToNum, str);
    connect(&watcher, &QFutureWatcher<int>::finished, this, [=] {
        if (future.isCanceled()) {
            qCritical() << "future failed" << QThread::currentThread();
            return;
        }

        QFuture<int> future2 = QtConcurrent::run(square, future.result());
        connect(&watcher2, &QFutureWatcher<int>::finished, this, [=] {
            qDebug() << "square result=" << future2.result()
                     << QThread::currentThread();
        });
        watcher2.setFuture(future2);
    });
    watcher.setFuture(future);
}

int Worker::convertStringToNum(const QString &str)
{
    qDebug() << __FUNCTION__ << QThread::currentThread();
    bool isOk;
    int num = str.toInt(&isOk);
    if (isOk) {
        qDebug() << "num=" << num;
    } else {
        MyException exception;
        exception.raise();
    }
    return num;
}

int Worker::square(int data)
{
    qDebug() << __FUNCTION__ << QThread::currentThread();
    return data * data;
}

