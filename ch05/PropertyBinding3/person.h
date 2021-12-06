#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fullName
               READ fullName
               WRITE setFullName
               BINDABLE bindableFullName)
public:
    explicit Person(QObject *parent = nullptr);
    QProperty<QString> firstName;
    QProperty<QString> lastName;
//    QProperty<QString> fullName;

    const QString &fullName() const;
    void setFullName(const QString &newFullName);
    QBindable<QString> bindableFullName();
signals:
    void fullNameChanged();
public:
    // Q_OBJECT_BINDABLE_PROPERTYはシグナルより後ろで定義する必要がある
    Q_OBJECT_BINDABLE_PROPERTY(Person,
                               QString,
                               b_fullName,
                               &Person::fullNameChanged)
};
#endif // PERSON_H
