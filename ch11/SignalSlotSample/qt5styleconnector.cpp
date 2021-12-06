#include "qt5styleconnector.h"
#include "sender.h"
#include "receiver.h"
#include <QDebug>

Qt5StyleConnector::Qt5StyleConnector(SignalType type, Sender *sender, Receiver *receiver,
                                     OverloadType overloadType, QObject *parent)
    : Connector(type, sender, receiver, parent), m_overloadType(overloadType)
{

}

void Qt5StyleConnector::setConnector()
{
    qDebug() << metaObject()->className() << __FUNCTION__;


    switch(signalType()) {
    case Connector::SignalType::NoArgumentType:
        connect(signalSender(), &Sender::valueChanged,
                signalReceiver(), &Receiver::setValue);
        break;
    case Connector::SignalType::IntValueType:
        connect(signalSender(), &Sender::value2Changed,
                signalReceiver(), &Receiver::setValueInt);
        break;
    case Connector::SignalType::IntValueType2:
        switch(m_overloadType) {
        case OverloadType::StaticType:
        {
            qDebug() << "connect StaticType";
            connect(signalSender(), static_cast<void (Sender::*)(int)>(&Sender::value3Changed),
                    signalReceiver(), static_cast<void (Receiver::*)(int)>(&Receiver::setValue3));
        }
            break;
        case OverloadType::FunctionPointerType:
        {
            qDebug() << "connect FunctionPointerType";
            void (Sender::*mySignal)(int) = &Sender::value3Changed;
            void (Receiver::*mySlot)(int) = &Receiver::setValue3;
            connect(signalSender(), mySignal, signalReceiver(), mySlot);
        }
            break;
        case OverloadType::QOverloadOf11Type:
        {
            qDebug() << "connect QOverloadOf11Type";
#if __cplusplus  >= 201103L
            connect(signalSender(), QOverload<int>::of(&Sender::value3Changed),
                    signalReceiver(), QOverload<int>::of(&Receiver::setValue3));
#else
            qDebug() << "Not support C++11 Version";
#endif
        }
            break;
        case OverloadType::QOverload14Type:
        {
            qDebug() << "connect QOverload14Type";
#if __cplusplus  >= 201402L
            connect(signalSender(), qOverload<int>(&Sender::value3Changed),
                    signalReceiver(), qOverload<int>(&Receiver::setValue3));
#else
            qDebug() << "Not support C++14 Version";
#endif
        }
            break;
        }
        break;
    case Connector::SignalType::StringType:
        switch(m_overloadType) {
        case OverloadType::StaticType:
        {
            qDebug() << "connect StaticType";
            connect(signalSender(), static_cast<void (Sender::*)(const QString&)>(&Sender::value3Changed),
                    signalReceiver(), static_cast<void (Receiver::*)(const QString&)>(&Receiver::setValue3));
        }
            break;
        case OverloadType::FunctionPointerType:
        {
            qDebug() << "connect FunctionPointerType";
            void (Sender::*mySignal)(const QString&) = &Sender::value3Changed;
            void (Receiver::*mySlot)(const QString&) = &Receiver::setValue3;
            connect(signalSender(), mySignal, signalReceiver(), mySlot);
        }
            break;
        case OverloadType::QOverloadOf11Type:
        {
            qDebug() << "connect QOverloadOf11Type";
#if __cplusplus  >= 201103L
            connect(signalSender(), QOverload<const QString&>::of(&Sender::value3Changed),
                    signalReceiver(), QOverload<const QString&>::of(&Receiver::setValue3));
#else
            qDebug() << "Not support C++11 Version";
#endif
        }
            break;
        case OverloadType::QOverload14Type:
        {
            qDebug() << "connect QOverload14Type";
#if __cplusplus  >= 201402L
            connect(signalSender(), qOverload<const QString&>(&Sender::value3Changed),
                    signalReceiver(), qOverload<const QString&>(&Receiver::setValue3));
#else
            qDebug() << "Not support C++14 Version";
#endif
        }
            break;
        }
        break;
    }

}
