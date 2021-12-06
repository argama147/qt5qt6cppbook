#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QFutureWatcher>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();
    void work(const QString& str);
signals:
    void canceled();
private:
    static int convertStringToNum(const QString &str);
    static int square(int data);
};

#endif // WORKER_H
