#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
    fullName.setBinding([&](){
        if(firstName.value().isEmpty() && lastName.value().isEmpty()) {
            return QString("");
        }
        return firstName.value() + " " + lastName.value();
    });
}
