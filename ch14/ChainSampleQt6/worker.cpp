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
    qDebug() << Q_FUNC_INFO;
}

void Worker::work(const QString &str)
{
    qDebug() << Q_FUNC_INFO << str;
    auto future = QtConcurrent::run(convertStringToNum, str)
                .then(square)
                .onFailed([](const MyException& e) {
                    qCritical() << "onFailed:" << e.what();
                    return -1;
                }
    );
    qInfo() << future.result();
}

int Worker::convertStringToNum(const QString &str)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    bool isOk;
    int num = str.toInt(&isOk);
    if (isOk) {
        qDebug() << "num=" << num;
    } else {
        QString reason = QString("%1 cannot convert").arg(str);
        MyException exception(reason);
        exception.raise();
    }
    return num;
}

int Worker::square(int data)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    return data * data;
}

