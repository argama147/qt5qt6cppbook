#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    Dialog *dialog = new Dialog;
    connect(dialog, &Dialog::finished, this,
            [=](int result){
        switch (result) {
        case QDialog::DialogCode::Accepted:
            ui->lineEdit->setText("accepted");
            break;
        case QDialog::DialogCode::Rejected:
            ui->lineEdit->setText("rejected");
            break;
        }
        delete dialog;
    });
    dialog->exec();
}

