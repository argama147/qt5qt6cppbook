#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendSignalNoArgument()
{
    qDebug() << __FUNCTION__;
    emit valueChanged();
}

void Sender::sendSignalIntValue(int value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
    emit value2Changed(value);
}

void Sender::sendSignalValue2(int value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
    emit value3Changed(value);
}

void Sender::sendSignalValue2(const QString &value)
{
    qDebug() << __FUNCTION__ << " value=" << value;
    emit value3Changed(value);
}
