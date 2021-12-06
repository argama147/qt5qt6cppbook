#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    QProperty<QString> firstName;
    QProperty<QString> lastName;
    QProperty<QString> fullName;
};

#endif // PERSON_H
