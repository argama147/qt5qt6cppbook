#include <QCoreApplication>

#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person person;
    qInfo() << "before fullName: " << person.fullName();

    auto handler = person.b_fullName.onValueChanged([&](){
        qInfo() << "onValueChanged: " << person.b_fullName;
    });

    // std::functionを使用した使い方
    std::function<void()> fn = [&]() {
        qInfo() << "std::function handler: " << person.b_fullName;
    };
    auto handler2 = person.b_fullName.onValueChanged(fn);

    person.firstName = "Satoshi";
    qInfo() << "after1 fullName: " << person.fullName();
    person.lastName = "Sakamoto";
    qInfo() << "after2 fullName: " << person.fullName();

    return a.exec();
}
