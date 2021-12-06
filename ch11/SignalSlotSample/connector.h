#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>

class Sender;
class Receiver;


class Connector : public QObject
{
    Q_OBJECT
public:
    enum class SignalType {
        NoArgumentType = 0,
        IntValueType,
        IntValueType2,
        StringType,
    };
    enum class OverloadType {
        StaticType = 0,
        FunctionPointerType,
        QOverloadOf11Type,
        QOverload14Type,
    };

    explicit Connector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent = nullptr);
    virtual void setConnector() = 0;
protected:
    Sender* signalSender();
    Receiver* signalReceiver();
    SignalType signalType();
private:
    SignalType m_signalType;
    Sender *m_sender;
    Receiver *m_receiver;
};

#endif // CONNECTOR_H
