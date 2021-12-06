#include "child.h"

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Parent *parent = new Parent();
    new Child(parent);
    delete parent;

    return a.exec();
}
