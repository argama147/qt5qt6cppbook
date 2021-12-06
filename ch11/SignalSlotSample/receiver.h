#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

public slots:
    void setValue();
    void setValueInt(int value);
    void setValue3(int value);
    void setValue3(const QString &value);
};

#endif // RECEIVER_H
