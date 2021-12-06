#include "widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 200);

    m_QPushButton = new QPushButton("push", this);
    connect(m_QPushButton, &QPushButton::clicked,
            this, &Widget::received);
}

Widget::~Widget()
{

}

void Widget::received()
{
    qDebug() << Q_FUNC_INFO;
    disconnect(m_QPushButton, &QPushButton::clicked,
               this, &Widget::received);
}
