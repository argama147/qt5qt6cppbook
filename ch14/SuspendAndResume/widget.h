#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtConcurrent>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QFutureWatcher<int> m_watcher;
    QStandardItemModel* m_model;

    void initializeUI();
    void initializeWathcher();
    static void work(QPromise<int> &promise);
    void writeLog(const QString& message);
};
#endif // WIDGET_H
