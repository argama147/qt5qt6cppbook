#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;
public:
    QSize sizeHint() const override;
private slots:
    void received();
private:
    QPushButton *m_QPushButton;
    QMetaObject::Connection m_connection;
};

#endif // WIDGET_H
