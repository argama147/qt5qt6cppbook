#include <QCoreApplication>

#include "receiver.h"
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender sender;
    Receiver receiver;

    //実行時Error
    //QObject::connect: Incompatible sender/receiver arguments
    //        Sender::changedValue1(int) --> Receiver::setValue2(int,int)
    QObject::connect(&sender, SIGNAL(changedValue1(int)),
                     &receiver, SLOT(setValue2(int, int)));

    //Build Error
//    QObject::connect(&sender, &Sender::changedValue1,
//                     &receiver, &Receiver::setValue2);

    //setValue1 value= 200
    QObject::connect(&sender, SIGNAL(changedValue2(int, int)),
                     &receiver, SLOT(setValue1(int)));

    //Build Error
//    QObject::connect(&sender, &Sender::changedValue2),
//                     &receiver, &Receiver::setValue1);

    //#### Default Valueの例 ####
    //実行時Error
    //QObject::connect: Incompatible sender/receiver arguments
    //Sender::changedValue2WithDefault(int) --> Receiver::setValue2(int,int)
    QObject::connect(&sender, SIGNAL(changedValue2WithDefault(int)),
                         &receiver, SLOT(setValue2(int, int)));

    //setValue2 value= 400 value2= 500
    QObject::connect(&sender, &Sender::changedValue2WithDefault,
                         &receiver, &Receiver::setValue2);

    //setValue2 value= 600 value2= 700
    QObject::connect(&sender, SIGNAL(changedValue2WithDefault2(int, int)),
                         &receiver, SLOT(setValue2(int, int)));

    //setValue2 value= 600 value2= 700
    QObject::connect(&sender, &Sender::changedValue2WithDefault2,
                         &receiver, &Receiver::setValue2);

    sender.sendSignal();
    return a.exec();
}
