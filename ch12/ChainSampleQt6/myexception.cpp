#include "myexception.h"

MyException::MyException(const QString& reason)
    : reason(reason)
{

}


void MyException::raise() const
{
    throw *this;
}

QException *MyException::clone() const
{
    return new MyException(*this);
}


const char *MyException::what() const noexcept
{
    return reason.toUtf8().data();
}
