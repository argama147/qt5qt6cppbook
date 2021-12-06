#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::setValue1(int value)
{
    qDebug() << __FUNCTION__ << "value=" << value;
}

void Receiver::setValue2(int value, int value2)
{
    qDebug() << __FUNCTION__ << "value=" << value << "value2=" << value2;

}
