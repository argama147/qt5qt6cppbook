#include <QCoreApplication>
#include <QDebug>
#include <QList>

class Number {
public:
    Number(int no) {
        m_no = no;
    }
    ~Number() {
        qDebug() << Q_FUNC_INFO << m_no;
    }
private:
    int m_no;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> numList;
    // Add1
    numList.append("One");
    numList.append("Two");
    numList.append("Three");
    qDebug() << numList;

    // Add2
    numList << "Four";
    qDebug() << numList;

    // Insert
    numList.insert(2, "Ten");
    qDebug() << numList;

    // Clear
    qDebug() << "numList.count" << numList.count();
    numList.clear();
    qDebug() << "cleared numList" << numList;
    qDebug() << "numList.count" << numList.count();

    QList<Number *> numPtrList;
    for (int i = 0; i < 2; ++i) {
        Number *number = new Number(i);
        numPtrList << number;
    }
    qDebug() << "numPtrList.count" << numPtrList.count();
    qDeleteAll(numPtrList);
    qDebug() << "numPtrList.count" << numPtrList.count();
    numPtrList.clear();
    qDebug() << "numPtrList" << numPtrList.count();

    // Remove
    numList.clear();
    numList << "One" << "Two" << "Three" << "One" << "Two" << "Three";
    numList.removeOne("Two");
    qDebug() << numList;
    numList.removeOne("One");
    qDebug() << numList;
    numList.removeAll("Three");
    qDebug() << numList;


    // for文
    numList.clear();
    numList << "One" << "Two" << "Three";
    for (int i = 0; i < numList.size(); ++i) {
        qDebug() << "numList[" << i << "]"
                 << numList[i] << numList.at(i);
        numList[i] = numList[i] + "!!";
//Build Error numList.at(i) = numList.at(i) + "!!";
    }
    qDebug() << numList;

    numList.clear();
    numList << "One" << "Two" << "Three";

    // foreach（非推奨）
    foreach (const QString &str, numList) {
        qDebug() << "str" << str;
    }

    // 範囲For文
    for(const QString &str : numList) {
        qDebug() << "str2" << str;
    }

    // STL Style Iterator
    QList<QString>::iterator stlIter;
    for (stlIter = numList.begin();
         stlIter != numList.end(); ++stlIter) {
        qDebug() << "stlIter" << *stlIter;
    }

    // Java Style Iterator（非推奨）
    QListIterator<QString> javaIter(numList);
    while (javaIter.hasNext()) {
        qDebug() << "javaIter" << javaIter.next();
    }

    return a.exec();
}
