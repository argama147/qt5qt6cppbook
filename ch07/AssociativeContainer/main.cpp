#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> numMap;

    // Set
    numMap["One"] = 1;
    numMap["Two"] = 2;
    numMap["Three"] = 3;
    qDebug() << numMap;

    // Insert
    numMap.insert("Seven", 10);
    numMap.insert("Seven", 7);
    qDebug() << numMap;

    // Get
    qDebug() << "get Two:" << numMap["Two"];
    qDebug() << "get Seven:" << numMap.value("Seven");

    // マップに含んでいるかどうか確認してからGet
    if (numMap.contains("Three")) {
        qDebug() << "get Three:" << numMap.value("Three");
    }

    // 範囲or文
    //warning:c++11 range-loop might detach Qtcontainer (QMap) [clazy-range-loop]
//    for (int num : numMap) {
//        qDebug() << "range-loop:" << num;
//    }
    for (int num : qAsConst(numMap)) {
        qDebug() << "range-loop:" << num;
    }

    // STL Style Iterator
    QMap<QString, int>::const_iterator i = numMap.constBegin();
    while (i != numMap.constEnd()) {
        qDebug()  << i.key() << ": " << i.value();
        ++i;
    }

    QList<int> list { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    QSet<int> set(list.begin(), list.end());
    qDebug() << set;

    return a.exec();
}
