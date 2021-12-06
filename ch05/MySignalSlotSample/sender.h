#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);
    void sendSignal();
signals:
    void valueChanged(int value);
};

#endif // SENDER_H
