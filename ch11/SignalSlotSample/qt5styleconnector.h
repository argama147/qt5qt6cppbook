#ifndef QT5STYLECONNECTOR_H
#define QT5STYLECONNECTOR_H

#include <QObject>
#include "connector.h"

class Qt5StyleConnector : public Connector
{
    Q_OBJECT
public:
    Qt5StyleConnector(SignalType type, Sender *sender, Receiver *receiver,
                      OverloadType overloadType = Connector::OverloadType::StaticType,
                      QObject *parent = nullptr);
    void setConnector() override;
private:
    OverloadType m_overloadType;
};

#endif // QT5STYLECONNECTOR_H
