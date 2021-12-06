#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 標準出力
    QTextStream out(stdout);
    out << "Hello World" << Qt::endl;

    return a.exec();
}
