#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);
    void sendSignalNoArgument();
    void sendSignalIntValue(int value);
    void sendSignalValue2(int value);
    void sendSignalValue2(const QString &value);

signals:
    void valueChanged();
    void value2Changed(int value);

    void value3Changed(int value);
    void value3Changed(const QString &value);
};

#endif // SENDER_H
