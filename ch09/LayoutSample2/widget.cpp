#include "widget.h"
#include "label.h"
#include "vboxlayout.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 300);

    QVBoxLayout *layout = new VBoxLayout();
    QLabel *label = new Label("label1");
    layout->addWidget(label);
    layout->setAlignment(label, Qt::AlignHCenter);

    layout->addWidget(new QPushButton("PushButton"));
    layout->addWidget(new QLabel("label2"));

    layout->setAlignment(Qt::AlignHCenter);
    layout->addStretch();

    setLayout(layout);
}

Widget::~Widget()
{
    qDebug() << Q_FUNC_INFO;
}

