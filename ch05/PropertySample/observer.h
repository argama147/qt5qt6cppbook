#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>

class Observer : public QObject
{
    Q_OBJECT
public:
    explicit Observer(QObject *parent = nullptr);

public slots:
    void nameChanged(const QString &name);
    void numChanged(int num);

};

#endif // OBSERVER_H
