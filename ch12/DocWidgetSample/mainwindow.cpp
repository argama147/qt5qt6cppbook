#include "mainwindow.h"
#include "form.h"
#include "customdockwidget.h"

#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget* dockWidget = new QDockWidget("QDockWidget1");
    dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget->setWidget(new Form(this));
    addDockWidget(Qt::TopDockWidgetArea, dockWidget);

    QDockWidget* dockWidget2 = new CustomDockWidget("QDockWidget2");
    dockWidget2->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget2->setWidget(new Form(this));
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget2);
}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(600, 300);
}
