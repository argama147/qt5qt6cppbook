#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::setValue()
{
    qDebug() << Q_FUNC_INFO;
}

void Receiver::setValueInt(int value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
}

void Receiver::setValue3(int value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
}

void Receiver::setValue3(const QString &value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
}
