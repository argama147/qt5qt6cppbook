#include "mymath.h"

class MyMath::MyMathPrivate {
public:
    int calculate(int x, int y);
private:
    int sum(int x, int y);
    int multiply(int x, int y);
};

int MyMath::MyMathPrivate::calculate(int x, int y) {
    return sum(x, y) + multiply(x, y);
}

int MyMath::MyMathPrivate::sum(int x, int y) {
    return x + y;
}
int MyMath::MyMathPrivate::multiply(int x, int y) {
    return x * y;
}

MyMath::MyMath()
{
}

MyMath::~MyMath()
{
    delete d;
}

int MyMath::calculate(int x, int y)
{
    return d->calculate(x, y);
}
