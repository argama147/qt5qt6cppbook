#include "widget.h"
#include "worker.h"

#include <QPushButton>
#include <QThread>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_threadButton = new QPushButton("Thread start", this);
    m_connection = connect(m_threadButton, &QPushButton::clicked,
                           this, &Widget::startThread);
}

Widget::~Widget()
{
    qDebug() << __FUNCTION__;
    m_thread->quit();
    m_thread->wait();
}

void Widget::startThread(bool b)
{
    Q_UNUSED(b);

    //１回のみスレッドを起動する.
    disconnect(m_connection);
    m_threadButton->setEnabled(false);

    m_thread = new QThread();
    Worker *worker = new Worker();
    worker->moveToThread(m_thread);

    //Thread開始時の動作.
    connect(m_thread, &QThread::started, worker, &Worker::doWork);

    //終了時メモリクリア.
    connect(worker, &Worker::finished, m_thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &QObject::deleteLater);
    connect(m_thread, &QThread::finished, m_thread, &Worker::deleteLater);

    //スレッド開始.
    m_thread->start();
}

QSize Widget::sizeHint() const
{
    return QSize(300, 200);
}
