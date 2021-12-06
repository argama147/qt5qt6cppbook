#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    new QPushButton("Hello World!!", &w);
    w.show();

    return a.exec();
}
