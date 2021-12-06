#include <QCoreApplication>
#include "sampledata.h"
#include "observer.h"

#include <QVariant>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SampleData data;
    Observer observer;

    QObject::connect(&data, &SampleData::nameChanged,
                     &observer, &Observer::nameChanged);
    QObject::connect(&data, &SampleData::numChanged,
                     &observer, &Observer::numChanged);

    data.setProperty("name", "Satoshi Sakamoto");
    data.setProperty("num", 1);

    return a.exec();
}
