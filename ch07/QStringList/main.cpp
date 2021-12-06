#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString numberList = "One,Two,Three";
    // 「,」で分解
    QStringList strList = numberList.split(",");
    for(const QString &str : strList) {
        qDebug() << "str" << str;
    }
    // 「/」で結合
    QString str = strList.join("/");
    qDebug() << "strList" << str;

    return a.exec();
}
