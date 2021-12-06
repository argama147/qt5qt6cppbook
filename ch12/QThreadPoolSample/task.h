#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();
    void run() override;
private:
    void work();
};

#endif // TASK_H
