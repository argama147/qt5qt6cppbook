#ifndef PERSON_H
#define PERSON_H

#include <QMetaType>
#include <QSharedDataPointer>

class Person
{
public:
    Person();
    Person(const Person &other);
    ~Person();

    Person &operator =(const Person &other);
    QString name() const;
    void setName(const QString &name);

    const void *debug() const;
    const void *debugNameAddr() const;
private:
    class PrivatePerson;
    QSharedDataPointer<PrivatePerson> d;
};

Q_DECLARE_METATYPE(Person)

#endif // PERSON_H
