#include "mywidget.h"

#include <QLabel>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    new QLabel("mywidget label", this);
}
