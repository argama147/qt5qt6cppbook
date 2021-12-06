#include "widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_QPushButton = new QPushButton("push", this);

    connect(m_QPushButton, &QPushButton::clicked,
            this, &Widget::received);
}

Widget::~Widget()
{

}

QSize Widget::sizeHint() const
{
    return QSize(300, 200);
}

void Widget::received()
{
    qDebug() << __FUNCTION__;
    disconnect(m_QPushButton, &QPushButton::clicked,
               this, &Widget::received);
}
