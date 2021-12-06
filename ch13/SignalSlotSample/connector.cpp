#include "connector.h"
#include "sender.h"
#include "receiver.h"


Connector::Connector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent)
    : QObject(parent), m_signalType(type), m_sender(sender), m_receiver(receiver)
{

}

Sender *Connector::signalSender()
{
    return m_sender;
}

Receiver *Connector::signalReceiver()
{
    return m_receiver;
}

Connector::SignalType Connector::signalType()
{
    return m_signalType;
}
