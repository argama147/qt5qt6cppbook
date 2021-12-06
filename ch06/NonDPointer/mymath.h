#ifndef MYMATH_H
#define MYMATH_H

class MyMath
{
public:
    MyMath();
    int calculate(int x, int y); // 計算する
private:
    int sum(int x, int y); // 加算する
    int multiply(int x, int y); // 乗算する
};

#endif // MYMATH_H
