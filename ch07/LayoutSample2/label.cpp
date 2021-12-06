#include "label.h"
#include <QDebug>

Label::Label(QWidget *parent) : QLabel(parent)
{

}

Label::Label(const QString &text, QWidget *parent, Qt::WindowFlags f)
    : QLabel(text, parent, f)
{

}

Label::~Label()
{
    qDebug() << __FUNCTION__;
}
