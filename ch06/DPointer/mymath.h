#ifndef MYMATH_H
#define MYMATH_H

class MyMath
{
public:
    MyMath();
    ~MyMath();
    int calculate(int x, int y);
private:
    class MyMathPrivate;
    MyMathPrivate *d;
};

#endif // MYMATH_H
