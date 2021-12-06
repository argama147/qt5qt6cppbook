#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    new QPushButton("button", this);
    setStyleSheet("Widget {background: yellow}");
}

Widget::~Widget()
{

}


QSize Widget::sizeHint() const
{
    return QSize(300, 200);
}
