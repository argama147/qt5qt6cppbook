#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    QSize sizeHint() const override;

private slots:
    void actFirst(bool checked = false);
    void actSecond(bool checked = false);
    void actThird(bool checked = false);
private:
    QAction *m_firstAction;
    QAction *m_secondAction;
    QAction *m_ThirdAction;

    void initalizeCentralWidget();
    void initalizeActions();
    void initalizeMenuBars();
};

#endif // MAINWINDOW_H
