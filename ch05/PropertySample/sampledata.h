#ifndef SAMPLEDATA_H
#define SAMPLEDATA_H

#include <QObject>

class SampleData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int num MEMBER m_num NOTIFY numChanged)

public:
    explicit SampleData(QObject *parent = nullptr);
    QString name() const;
    void setName(const QString& name);

signals:
    void nameChanged(const QString &name);
    void numChanged(int name);

private:
    QString m_name;
    int m_num;
};

#endif // SAMPLEDATA_H
