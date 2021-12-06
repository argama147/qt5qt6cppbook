#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#include "sender.h"
#include "receiver.h"
#include "qt4styleconnector.h"
#include "qt5styleconnector.h"
#include "lamdastyle1connector.h"
#include "lamdastyle2connector.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectButton_clicked()
{
    m_sender.reset(new Sender());
    m_receiver.reset(new Receiver());

    Connector::SignalType signalType;

    switch(ui->toolBox->currentIndex()) {
    case 0:
        switch(ui->signalTypeComboBox->currentIndex()) {
        case 0:
            signalType = Connector::SignalType::NoArgumentType;
            break;
        case 1:
            signalType = Connector::SignalType::IntValueType;
            break;
        case 2:
            signalType = Connector::SignalType::IntValueType2;
            break;
        case 3:
            signalType = Connector::SignalType::StringType;
            break;
        }

        switch(ui->connectorComboBox->currentIndex()) {
        case 0:
            m_connector.reset(new Qt4StyleConnector(signalType, m_sender.data(), m_receiver.data()));
            break;
        case 1:
            m_connector.reset(new Qt5StyleConnector(signalType, m_sender.data(), m_receiver.data()));
            break;
        case 2:
            m_connector.reset(new LamdaStyle1Connector(signalType, m_sender.data(), m_receiver.data()));
            break;
        case 3:
            m_connector.reset(new LamdaStyle2Connector(signalType, m_sender.data(), m_receiver.data()));
            break;
        }
        break;
    case 1:
        Connector::OverloadType overLoadType;
        switch (ui->overLoadComboBox->currentIndex()) {
        case 0:
            overLoadType = Connector::OverloadType::StaticType;
            break;
        case 1:
            overLoadType = Connector::OverloadType::FunctionPointerType;
            break;
        case 2:
            overLoadType = Connector::OverloadType::QOverloadOf11Type;
            break;
        case 3:
            overLoadType = Connector::OverloadType::QOverload14Type;
            break;
        }

        switch (ui->signalTypeOverloadComboBox->currentIndex()) {
        case 0:
            signalType = Connector::SignalType::IntValueType2;
            break;
        case 1:
            signalType = Connector::SignalType::StringType;
            break;
        }
        m_connector.reset(
                   new Qt5StyleConnector(signalType,
                                         m_sender.data(),
                                         m_receiver.data(),
                                         overLoadType));
        break;
    }

    if (!m_connector.isNull()) {
        m_connector->setConnector();
    }
}

void Widget::on_sendSignalButton_clicked()
{
    switch(ui->toolBox->currentIndex()) {
    case 0: //基本動作.
        switch(ui->signalTypeComboBox->currentIndex()) {
        case 0:
            m_sender->sendSignalNoArgument();
            break;
        case 1:
            m_sender->sendSignalIntValue(100);
            break;
        }
        break;
    case 1: //Overload
        switch(ui->signalTypeOverloadComboBox->currentIndex()) {
        case 0:
            m_sender->sendSignalValue2(200);
            break;
        case 1:
            m_sender->sendSignalValue2("test");
            break;
        }
        break;
    }
}
