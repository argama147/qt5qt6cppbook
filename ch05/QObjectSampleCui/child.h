#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class Child : public Parent
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = nullptr);
    virtual ~Child();

signals:

public slots:
};

#endif // CHILD_H
