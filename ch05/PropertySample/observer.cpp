#include "observer.h"

#include <QDebug>

Observer::Observer(QObject *parent) : QObject(parent)
{

}

void Observer::nameChanged(const QString &name)
{
    qInfo() << Q_FUNC_INFO << "name=" << name;
}

void Observer::numChanged(int num)
{
    qInfo() << Q_FUNC_INFO << "name=" << num;
}
