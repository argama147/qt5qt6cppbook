#ifndef CUSTOMDOCKWIDGET_H
#define CUSTOMDOCKWIDGET_H

#include <QDockWidget>
#include <QWidget>

class CustomDockWidget : public QDockWidget
{
public:
    explicit CustomDockWidget(const QString &title, QWidget *parent = nullptr);
    ~CustomDockWidget();
};

#endif // CUSTOMDOCKWIDGET_H
