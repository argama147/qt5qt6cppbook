#include <QCoreApplication>

#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Person p1;
        p1.setName("sakamoto147");
        Person p2(p1);
        Person p3 = p1;
        qDebug() << p1.debug() << p2.debug() << p3.debug()
                 << p1.debugNameAddr() << p2.debugNameAddr() << p3.debugNameAddr();
        p2.setName("sakamoto246");
        qDebug() << p1.debug() << p2.debug() << p3.debug()
                 << p1.debugNameAddr() << p2.debugNameAddr() << p3.debugNameAddr();
        p3.setName("sakamoto359");
        qDebug() << p1.debug() << p2.debug() << p3.debug()
                 << p1.debugNameAddr() << p2.debugNameAddr() << p3.debugNameAddr();
        p3.setName("sakamoto777");
        qDebug() << p1.debug() << p2.debug() << p3.debug()
                 << p1.debugNameAddr() << p2.debugNameAddr() << p3.debugNameAddr();
    }
    return a.exec();
}
