#include "widget.h"
#include "person.h"

#include <QApplication>
#include <QDebug>
#include <QDate>

void convertString() {
    qInfo() << Q_FUNC_INFO << "start";


    // QString --> QVariant
    QString text("hello");
    QVariant variant1(text);
    qInfo() << "variant1" << variant1
            << "typeName" << variant1.typeName();
    QVariant variant2;
    variant2.setValue(text);

    QVariant variant3 = QVariant::fromValue(text);

    // QVariant --> QString
    if (variant1.canConvert<QString>()) {
        QString text1 = variant1.toString();
        QString text2 = variant1.value<QString>();
        QString text3 = qvariant_cast<QString>(variant1);
    }

    QString str = "100";
    QVariant variant4(str);

    if (variant4.canConvert<int>()) {
        int textInt = variant4.toInt();
        qInfo() << "textInt" << textInt;
    }
    if (variant4.canConvert<QString>()) {
        QString textString = variant4.toString();
        qInfo() << "TextString" << textString;
    }
    qInfo() << Q_FUNC_INFO << "end";
}

void convertColor() {
    qInfo() << Q_FUNC_INFO << "start";

    QColor colorBefore(Qt::red);
    qInfo() << "colorBefore" << colorBefore;

    QVariant variantColor1(colorBefore);
    qInfo() << "variantColor1" << variantColor1
            << "typeName" << variantColor1.typeName();

    QVariant variantColor2;
    variantColor2.setValue(colorBefore);
    qInfo() << "variant2" << variantColor2;

    QVariant variant3 = QVariant::fromValue(colorBefore);
    qInfo() << "variant3" << variant3;

    if (variantColor1.canConvert<QColor>()) {
//        QColor color1 = variantColor1.toColor(); toColor()は存在しない
        QColor color2 = variantColor1.value<QColor>();
        QColor color3 = qvariant_cast<QColor>(variantColor1);
        qInfo() << "color2" << color2 << "color3" << color3;
    }
    qInfo() << Q_FUNC_INFO << "end";
}


void convertStdVariant() {
    qInfo() << Q_FUNC_INFO << "start";
    // std::variant -> QVariant
    struct ClassA { void f() { qDebug() << "ClassA.f()"; } };
    struct ClassB { void f() { qDebug() << "ClassB.f()"; } };
    struct ClassC { void f() { qDebug() << "ClassC.f()"; } };

    std::variant<ClassA, ClassB, ClassC> stdVariant = ClassA{};
    QVariant variantStd = QVariant::fromStdVariant(stdVariant);
    qInfo() << "variantStd" << variantStd;

    // QVariant -> std::variant
    qInfo() << "variantStd.canConvert<>()"
            << variantStd.canConvert<std::variant<ClassA, ClassB, ClassC>>();
    if (variantStd.canConvert<ClassA>()) {
        std::variant<ClassA, ClassB, ClassC> stdVariantAfter;
        stdVariantAfter = variantStd.value<std::variant<ClassA, ClassB, ClassC>>();
        ClassA& clsA = std::get<ClassA>(stdVariantAfter);
        clsA.f();
        ClassA clsA2 = variantStd.value<ClassA>();
        clsA2.f();
    }
    qInfo() << Q_FUNC_INFO << "end";
}

void convertVoidPtr() {
    qInfo() << Q_FUNC_INFO << "start";
    char c[] = "123";
    void *ptr = &c;
    qInfo() << Q_FUNC_INFO << "ptr" << ptr;
//    QVariant variantPtr(ptr); // build error
    QVariant variantPtr1;
    variantPtr1.setValue(ptr);
    qInfo() << "variantPtr1" << variantPtr1
            << "typeName" << variantPtr1.typeName();

    QVariant variantPtr2 = QVariant::fromValue(ptr);

    if (variantPtr1.canConvert<void *>()) {
        void* ptrAfter1 = variantPtr1.value<void *>();
        qInfo() << Q_FUNC_INFO << "ptrAfter1" << ptrAfter1;
    }

    if (variantPtr2.canConvert<void *>()) {
        void* ptrAfter2 = qvariant_cast<void *>(variantPtr2);
        qInfo() << Q_FUNC_INFO << "ptrAfter2" << ptrAfter2;
    }
    qInfo() << Q_FUNC_INFO << "end";
}

void convertOriginalType() {
    qInfo() << Q_FUNC_INFO << "start";
    Person person;
    person.setName("sakamoto");

//    QVariant variantPerson1(person); build error
    QVariant variantPerson2;
    variantPerson2.setValue(person);
    qInfo() << "typeName" << variantPerson2.typeName();
    if (variantPerson2.canConvert<Person>()) {
        Person personAfter = variantPerson2.value<Person>();
        qInfo() << "nameAfter" << personAfter.name();
    }
    qInfo() << Q_FUNC_INFO << "end";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    convertString();
    convertColor();
    convertVoidPtr();
    convertStdVariant();
    convertOriginalType();

    return a.exec();
}
