#include "myexception.h"

MyException::MyException()
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
