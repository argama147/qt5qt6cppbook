#include "widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_QPushButton = new QPushButton("push", this);

    m_connection = connect(m_QPushButton, &QPushButton::clicked,[=](bool checked) {
        Q_UNUSED(checked);
        qDebug() << "clicked";
        disconnect(m_connection);
    });
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
}
