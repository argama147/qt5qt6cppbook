#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

public slots:
    void setValue1(int value);
    void setValue2(int value, int value2);
};

#endif // RECEIVER_H
