#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendSignal()
{
    qDebug() << Q_FUNC_INFO;
    emit valueChanged(100);
}
