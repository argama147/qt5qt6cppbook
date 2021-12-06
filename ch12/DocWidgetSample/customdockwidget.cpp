#include "customdockwidget.h"

#include <QDebug>

CustomDockWidget::CustomDockWidget(const QString &title, QWidget *parent)
    : QDockWidget(title, parent)
{

}

CustomDockWidget::~CustomDockWidget()
{
    qInfo() << Q_FUNC_INFO;
}
