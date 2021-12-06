#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QObject>

class Example : public QObject
{
    Q_OBJECT
public:
    explicit Example(QObject *parent = nullptr);

signals:
    void valueChanged(int value);
public slots:
    void setValue(int value);
protected slots:
        void setValue2(int value);
private slots:
        void setValue3(int value);
};

#endif // EXAMPLE_H
