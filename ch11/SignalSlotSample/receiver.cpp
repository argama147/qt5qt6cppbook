#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::setValue()
{
    qDebug() << __FUNCTION__;
}

void Receiver::setValueInt(int value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
}

void Receiver::setValue3(int value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
}

void Receiver::setValue3(const QString &value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
}
