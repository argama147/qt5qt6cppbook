#include "mainwindow.h"

#include <QAction>
#include <QPushButton>
#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //セントラルウィジェットを初期化する.
    initalizeCentralWidget();
    //アクションを初期化する.
    initalizeActions();
    //メニューバーを初期化する.
    initalizeMenuBars();
}

MainWindow::~MainWindow()
{

}


QSize MainWindow::sizeHint() const
{
    return QSize(400, 300);
}

void MainWindow::actFirst(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << __FUNCTION__;
}

void MainWindow::actSecond(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << __FUNCTION__;
}

void MainWindow::actThird(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << __FUNCTION__;
}

void MainWindow::initalizeCentralWidget()
{
    QWidget *widget = new QWidget(this);
    new QPushButton("push", widget);

    setCentralWidget(widget);
}

void MainWindow::initalizeActions()
{
    m_firstAction = new QAction("&FirstAction");
    connect(m_firstAction, &QAction::triggered,
            this, &MainWindow::actFirst);
    m_secondAction = new QAction("&SecondAction");
    connect(m_secondAction, &QAction::triggered,
            this, &MainWindow::actSecond);
    m_ThirdAction = new QAction("&ThirdAction");
    connect(m_ThirdAction, &QAction::triggered,
            this, &MainWindow::actThird);
}

void MainWindow::initalizeMenuBars()
{
    QMenu *firstMenu = menuBar()->addMenu("Menu&1");
    firstMenu->addAction(m_firstAction);
    firstMenu->addAction(m_secondAction);

    QMenu *secondMenu = menuBar()->addMenu("Menu&2");
    secondMenu->addAction(m_ThirdAction);
}


