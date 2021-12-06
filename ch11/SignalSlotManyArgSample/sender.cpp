#include "sender.h"
#include <QDebug>

Sender::Sender(QObject *parent) : QObject(parent)
{

}

void Sender::sendSignal()
{
    qDebug() << __FUNCTION__;
    emit changedValue1(100);
    emit changedValue2(200, 300);
    emit changedValue2WithDefault(400);
    emit changedValue2WithDefault2(600, 700);

}
