#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QException>

class MyException : public QException
{
public:
    MyException();

    // QException interface
public:
    void raise() const override;
    QException *clone() const override;
};

#endif // MYEXCEPTION_H
