#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::setValue1(int value)
{
    qDebug() << Q_FUNC_INFO << "value=" << value;
}

void Receiver::setValue2(int value, int value2)
{
    qDebug() << Q_FUNC_INFO << "value=" << value << "value2=" << value2;

}
