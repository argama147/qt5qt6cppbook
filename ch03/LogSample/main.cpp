#include <QCoreApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Debug Message";
    qInfo() << "Info Message";
    qWarning() << "qWarning Message";
    qCritical() << "qCritical Message";

    return a.exec();
}
