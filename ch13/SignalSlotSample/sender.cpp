#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendSignalNoArgument()
{
    qDebug() << Q_FUNC_INFO;
    emit valueChanged();
}

void Sender::sendSignalIntValue(int value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
    emit value2Changed(value);
}

void Sender::sendSignalValue2(int value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
    emit value3Changed(value);
}

void Sender::sendSignalValue2(const QString &value)
{
    qDebug() << Q_FUNC_INFO << " value=" << value;
    emit value3Changed(value);
}
