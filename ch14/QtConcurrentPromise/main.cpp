#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>
#include <QObject>

void convertStringToNum(QPromise<int> &promise, const QString &str)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    bool isOk;
    int num = str.toInt(&isOk);
    if (isOk) {
        qDebug() << "num=" << num;
    } else {
        num = -1;
    }
    promise.addResult(num);
}

void exampleRun() {
    qDebug() << Q_FUNC_INFO;

    QString str = "3";
    auto future = QtConcurrent::run(convertStringToNum, str);
    qInfo() << Q_FUNC_INFO << "result=" << future.result();
}

void exampleTask() {
    qDebug() << Q_FUNC_INFO;

    QString str = "100";
    int result = QtConcurrent::task(&convertStringToNum)
            .withArguments(str).spawn().result();
    qInfo() << Q_FUNC_INFO << "result=" << result;
}

void exampleThreadStart() {
    qDebug() << Q_FUNC_INFO;

    QPromise<int> promise;
    QFuture<int> future = promise.future();

    QString str = "10";
    QScopedPointer<QThread> thread(
                QThread::create(
                    [&](QPromise<int> promise) {
        promise.start();
        convertStringToNum(promise, str);
        promise.finish();
    }, std::move(promise)));
    thread->start();
    qInfo() << "thread start";
    future.waitForFinished(); // block
    qInfo() << Q_FUNC_INFO << "result=" << future.result();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    exampleRun();
    exampleTask();
    exampleThreadStart();

    return a.exec();
}
