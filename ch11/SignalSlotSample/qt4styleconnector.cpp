#include "qt4styleconnector.h"
#include "sender.h"
#include "receiver.h"
#include <QDebug>

Qt4StyleConnector::Qt4StyleConnector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent)
    : Connector(type, sender, receiver, parent)
{

}

void Qt4StyleConnector::setConnector()
{
    qDebug() << metaObject()->className() << __FUNCTION__;

    switch(signalType()) {
    case Connector::SignalType::NoArgumentType:
        connect(signalSender(), SIGNAL(valueChanged()),
                signalReceiver(), SLOT(setValue()));
        break;
    case Connector::SignalType::IntValueType:
        connect(signalSender(), SIGNAL(value2Changed(int)),
                signalReceiver(), SLOT(setValueInt(int)));
        break;
    default:
        qDebug() << metaObject()->className() << __FUNCTION__ << "No Implements.";
        break;
    }
}

