#include "mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    new QPushButton("push", widget);

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{

}


QSize MainWindow::sizeHint() const
{
    return QSize(400, 300);
}
