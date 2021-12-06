#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QException>

class MyException : public QException
{
public:
    MyException(const QString& reason);

    // QException interface
public:
    void raise() const override;
    QException *clone() const override;
    const char *what() const noexcept override;
private:
    QString reason;
};

#endif // MYEXCEPTION_H
