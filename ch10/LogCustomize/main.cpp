#include <QCoreApplication>
#include "iostream"

void logSettings(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        std::cerr << "[D] %s\n", localMsg.constData();
        break;
    case QtInfoMsg:
        std::cerr << "[I] %s\n", localMsg.constData();
        break;
    case QtWarningMsg:
        std::cerr << "[W] %s\n", localMsg.constData();
        break;
    case QtCriticalMsg:
        std::cerr <<  "[C] %s\n", localMsg.constData();
        break;
    case QtFatalMsg:
        std::cerr << "[F] %s\n", localMsg.constData();
        break;
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(logSettings); //【1】
    QCoreApplication a(argc, argv);

    qDebug() << "qDebug Message";
    qInfo() << "qInfo Message";
    qWarning() << "qWarning Message";
    qCritical() << "qCritical Message";

    return a.exec();
}
