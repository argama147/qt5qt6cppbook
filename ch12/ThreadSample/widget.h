#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class Worker;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;
    QSize sizeHint() const override;
private slots:
    void startThread(bool b);
private:
    QThread *m_thread;
    QPushButton *m_threadButton;
    QMetaObject::Connection m_connection;
};

#endif // WIDGET_H
