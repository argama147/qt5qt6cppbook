#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Sender;
class Receiver;
class Connector;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_connectButton_clicked();

    void on_sendSignalButton_clicked();

private:
    Ui::Widget *ui;

    QSharedPointer<Sender> m_sender;
    QSharedPointer<Receiver> m_receiver;
    QSharedPointer<Connector> m_connector;

    void connectOverload(int );

};

#endif // WIDGET_H
