#include "parent.h"
#include <QDebug>

Parent::Parent(QObject *parent) : QObject(parent)
{
}

Parent::~Parent()
{
    qDebug() << Q_FUNC_INFO;
}
