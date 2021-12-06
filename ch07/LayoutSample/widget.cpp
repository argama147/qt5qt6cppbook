#include "widget.h"
#include "label.h"
#include "vboxlayout.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new VBoxLayout();
    layout->addWidget(new Label("label1"));
    layout->addWidget(new QPushButton("PushButton"));
    layout->addWidget(new QLabel("label2"));
    layout->addWidget(new QLineEdit());

    setLayout(layout);
}

Widget::~Widget()
{
    qDebug() << __FUNCTION__;
}

