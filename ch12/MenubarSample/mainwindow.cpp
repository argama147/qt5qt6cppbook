#include "mainwindow.h"

#include <QAction>
#include <QPushButton>
#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 300);
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

void MainWindow::actFirst(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::actSecond(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::actThird(bool checked)
{
    Q_UNUSED(checked);
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::initalizeCentralWidget()
{
    QWidget *widget = new QWidget(this);
    new QPushButton("push", widget);

    setCentralWidget(widget);
}

void MainWindow::initalizeActions()
{
    m_firstAction = new QAction("&FirstAction", this);
    connect(m_firstAction, &QAction::triggered,
            this, &MainWindow::actFirst);
    m_secondAction = new QAction("&SecondAction", this);
    connect(m_secondAction, &QAction::triggered,
            this, &MainWindow::actSecond);
    m_ThirdAction = new QAction("&ThirdAction", this);
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


