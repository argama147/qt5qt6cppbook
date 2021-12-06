#include "lamdastyle1connector.h"
#include "sender.h"
#include "receiver.h"
#include <QDebug>

LamdaStyle1Connector::LamdaStyle1Connector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent)
    : Connector(type, sender, receiver, parent)
{

}

void LamdaStyle1Connector::setConnector()
{
    qDebug() << metaObject()->className() << __FUNCTION__;


    switch(signalType()) {
    case Connector::SignalType::NoArgumentType:
        connect(signalSender(), &Sender::valueChanged,
                [this]() {
            qDebug() << metaObject()->className() << ":slot called.";
        });
        break;
    case Connector::SignalType::IntValueType:
        connect(signalSender(), &Sender::value2Changed,
                [=](int value) {
            qDebug() << metaObject()->className() << ":slot called. value=" << value;
        });
        break;
    default:
        qDebug() << metaObject()->className() << __FUNCTION__ << "No Implements.";
        break;
    }
}


