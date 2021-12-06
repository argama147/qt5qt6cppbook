#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>
#include <QObject>

void work() {
    qDebug() << Q_FUNC_INFO;
}

int convertStringToNum(const QString &str)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    bool isOk;
    int num = str.toInt(&isOk);
    if (isOk) {
        qDebug() << "num=" << num;
    } else {
        num = -1;
    }
    return num;
}

void example1() {
    qDebug() << Q_FUNC_INFO;
    QFuture<void> future = QtConcurrent::run(work);
}

void example2() {
    qDebug() << Q_FUNC_INFO;
    QThreadPool* threadPool = QThreadPool::globalInstance();
    QFuture<void> future = QtConcurrent::run(threadPool, work);
}

void example3() {
    qDebug() << Q_FUNC_INFO;
    QString str = "2";
    QFuture<int> future = QtConcurrent::run(convertStringToNum, str);
    qInfo() << "result=" << future.result();
}

void example4() {
    qDebug() << Q_FUNC_INFO;
    QString str = "2";
    QFuture<int> future = QtConcurrent::run([=]() {
        return convertStringToNum(str);
    });
    qInfo() << "result=" << future.result();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    example1();
//    example2();
//    example3();
//    example4();
    return a.exec();
}
