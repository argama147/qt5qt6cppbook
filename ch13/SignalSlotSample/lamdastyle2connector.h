#ifndef LAMDASTYLE2CONNECTOR_H
#define LAMDASTYLE2CONNECTOR_H

#include <QObject>
#include "connector.h"

class LamdaStyle2Connector : public Connector
{
    Q_OBJECT
public:
    LamdaStyle2Connector(SignalType type, Sender *sender, Receiver *receiver, QObject *parent = nullptr);
    void setConnector() override;
};

#endif // LAMDASTYLE2CONNECTOR_H
