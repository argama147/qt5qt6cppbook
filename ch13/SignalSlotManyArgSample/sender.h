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
    void changedValue1(int value);
    void changedValue2(int value, int value2);
    void changedValue2WithDefault(int value, int value2 = 500);
    void changedValue2WithDefault2(int value, int value2 = 500);
};

#endif // SENDER_H
