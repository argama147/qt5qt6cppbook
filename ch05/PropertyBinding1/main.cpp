#include <QCoreApplication>
#include <QDebug>

#include "person.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person person;
    qInfo() << "before fullName: " << person.fullName;

    auto handler = person.fullName.onValueChanged([&]() {
        qInfo() << "handler: " << person.fullName;
    });

    person.firstName = "Satoshi";
    qInfo() << "after1 fullName: " << person.fullName;
    person.lastName = "Sakamoto";
    qInfo() << "after2 fullName: " << person.fullName;

    return a.exec();
}
