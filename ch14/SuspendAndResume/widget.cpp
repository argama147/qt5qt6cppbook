#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QFutureWatcher>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_model(new QStandardItemModel)
{
    ui->setupUi(this);

    initializeUI();
    initializeWathcher();
}

Widget::~Widget()
{
    if (m_watcher.isRunning()) {
        m_watcher.cancel();
    }
    delete ui;
}

void Widget::work(QPromise<int> &promise)
{
    for (int i = 0; i <= 100; i = i + 10) {
        QThread::sleep(1);
        promise.setProgressValue(i);
        promise.suspendIfRequested();
        if (promise.isCanceled()) {
            qDebug() << "isCanceled() is true.";
            return;
        }
    }
}

void Widget::writeLog(const QString &message)
{
   qDebug() << message;

   QStandardItem* item = new QStandardItem();
   item->setText(message);
   item->setEditable(false);
   Q_CHECK_PTR(m_model);
   m_model->appendRow(item);
}

void Widget::on_pushButton_clicked()
{
    if (!m_watcher.isRunning()) {
        m_watcher.setFuture(QtConcurrent::run(work));
        ui->pushButton->setText("Stop");
    } else {
        m_watcher.cancel();
        ui->pushButton->setText("Start");
    }
}

void Widget::on_pushButton_2_clicked()
{
    qDebug() << Q_FUNC_INFO;
    if (!m_watcher.isSuspended()) {
        m_watcher.suspend();
        ui->pushButton_2->setText("Resume");
    } else {
        m_watcher.resume();
        ui->pushButton_2->setText("Suspend");
    }
}

void Widget::initializeUI()
{
    // Button
    connect(ui->pushButton, &QPushButton::clicked, [=](){
       ui->pushButton_2->setEnabled(!ui->pushButton_2->isEnabled());
    });

    // Model
    ui->listView->setModel(m_model);

    // リストの枠に溢れるほどデータが追加されたら自動的に下側にスクロールする
    connect(ui->listView->model(), &QStandardItemModel::rowsInserted,
            ui->listView, &QAbstractItemView::scrollToBottom);
}

void Widget::initializeWathcher()
{
    connect(&m_watcher,
            &QFutureWatcherBase::progressValueChanged,
            [=](int progress){
        writeLog(QString("progress=%1").arg(progress));
    });
    connect(&m_watcher,
            &QFutureWatcherBase::progressValueChanged,
            ui->progressBar, &QProgressBar::setValue);
    connect(&m_watcher,
            &QFutureWatcherBase::started,
            [=](){
        writeLog(QString("started"));
    });
    connect(&m_watcher,
            &QFutureWatcherBase::canceled,
            [=](){
        writeLog(QString("canceled"));
        ui->progressBar->setValue(0);
    });
    connect(&m_watcher,
            &QFutureWatcherBase::finished,
            [=](){
        writeLog(QString("finished"));
        ui->pushButton->setText("Start");
        ui->pushButton_2->setEnabled(false);
    });
    connect(&m_watcher,
            &QFutureWatcherBase::suspended,
            [=](){
        writeLog(QString("suspended"));
    });
    connect(&m_watcher,
            &QFutureWatcherBase::resumed,
            [=](){
        writeLog(QString("resumed"));
    });
}

