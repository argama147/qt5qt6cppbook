#include "sampledata.h"

SampleData::SampleData(QObject *parent) : QObject(parent)
{

}

QString SampleData::name() const
{
    return m_name;
}

void SampleData::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}
