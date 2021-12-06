#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    virtual ~Widget() override;
    QSize sizeHint() const override;
};

#endif // WIDGET_H
