#ifndef QT4STYLECONNECTOR_H
#define QT4STYLECONNECTOR_H

#include <QObject>
#include "connector.h"

class Qt4StyleConnector : public Connector
{
    Q_OBJECT
public:
    Qt4StyleConnector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent = nullptr);
    void setConnector() override;
};

#endif // QT4STYLECONNECTOR_H
