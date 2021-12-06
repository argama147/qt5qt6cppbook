#ifndef SAMPLE_H
#define SAMPLE_H

#include <QObject>

class Sample : public QObject
{
    Q_OBJECT
public:
    explicit Sample(QObject *parent = nullptr);

signals:

};

#endif // SAMPLE_H
