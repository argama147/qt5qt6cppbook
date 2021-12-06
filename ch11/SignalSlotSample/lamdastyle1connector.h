#ifndef LAMDASTYLE1CONNECTOR_H
#define LAMDASTYLE1CONNECTOR_H

#include <QObject>
#include "connector.h"

class LamdaStyle1Connector : public Connector
{
    Q_OBJECT
public:
    LamdaStyle1Connector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent = nullptr);
    void setConnector() override;
};

#endif // LAMDASTYLE1CONNECTOR_H
