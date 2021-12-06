#include "widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 200);

    QPushButton *btn = new QPushButton("push", this);
    connect(btn, &QPushButton::clicked,
            this, &Widget::received);
}

Widget::~Widget()
{

}

void Widget::received()
{
    qDebug() << Q_FUNC_INFO;
}
