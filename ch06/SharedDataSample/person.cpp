#include "person.h"
#include <QDebug>

class Person::PrivatePerson : public QSharedData
{
public:
    PrivatePerson();
    PrivatePerson(const PrivatePerson &other);
    ~PrivatePerson();
    QString name;
};

Person::PrivatePerson::PrivatePerson()
    : QSharedData()
{
    qDebug() << Q_FUNC_INFO << this;
}

Person::PrivatePerson::PrivatePerson(const PrivatePerson &other)
    : QSharedData(other)
    , name(other.name)
{
    qDebug() << Q_FUNC_INFO << this;
}

Person::PrivatePerson::~PrivatePerson(){
    qDebug() << Q_FUNC_INFO << this;
}

Person::Person()
    : d(new PrivatePerson)
{
}

Person::Person(const Person &other)
    : d(other.d)
{
}

Person::~Person()
{
}

Person &Person::operator =(const Person &other)
{
    d = other.d;
    return *this;
}

QString Person::name() const
{
    return d->name;
}

void Person::setName(const QString &name)
{
    d->name = name;
}

const void *Person::debug() const
{
    return d.constData();
}

const void *Person::debugNameAddr() const
{
    return &d.constData()->name;
}
