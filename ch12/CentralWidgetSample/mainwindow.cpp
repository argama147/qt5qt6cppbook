#include "mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 300);
    initalizeCentralWidget();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initalizeCentralWidget()
{
    QWidget *widget = new QWidget();
    new QPushButton("push", widget);
    setCentralWidget(widget);
}
