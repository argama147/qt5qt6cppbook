#include "mymath.h"

MyMath::MyMath()
{
}

int MyMath::calculate(int x, int y) {
    return sum(x, y) + multiply(x, y);
}

int MyMath::MyMath::sum(int x, int y) {
    return x + y;
}
int MyMath::MyMath::multiply(int x, int y) {
    return x * y;
}
