#include "widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 200);

    m_QPushButton = new QPushButton("push", this);
    m_connection = connect(m_QPushButton, &QPushButton::clicked,[=]() {
        qDebug() << "clicked";
        disconnect(m_connection);
    });
}

Widget::~Widget()
{

}

void Widget::received()
{
    qDebug() << Q_FUNC_INFO;
}
