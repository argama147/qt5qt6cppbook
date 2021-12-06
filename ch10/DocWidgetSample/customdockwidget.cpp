#include "customdockwidget.h"

#include <QDebug>

CustomDockWidget::CustomDockWidget(const QString &title, QWidget *parent)
    : QDockWidget(title, parent)
{

}

CustomDockWidget::~CustomDockWidget()
{
    qInfo() << __FUNCTION__;
}
