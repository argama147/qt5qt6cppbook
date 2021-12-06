#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>
#include <QObject>

void example1() {
    qDebug() << __FUNCTION__;
    QtConcurrent::task([]{
        qDebug() << "Task Thread" << QThread::currentThread();
    }).spawn();
}

void example2() {
    qDebug() << __FUNCTION__;
    auto task = [](const QString &s){ qDebug() << ("Hello, " + s); };
    auto t = QtConcurrent::task(std::move(task))
            .withArguments("World")
            .spawn();
}

void example3() {
    qDebug() << __FUNCTION__;
    auto future = QtConcurrent::task([]{
        qDebug() << "Future" << QThread::currentThread();
        return 42;
    }).spawn();
    auto result = future.result();
    qDebug() << "result" << result << QThread::currentThread();
}

void example4() {
    QString result("Hello, world!");
    QtConcurrent::task(&QString::chop)
        .withArguments(&result, 8)
        .spawn()
        .waitForFinished();
    qDebug() << result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Main Thread" << QThread::currentThread();

    example1();
//    example2();
//    example3();
//    example4();


    return a.exec();
}
