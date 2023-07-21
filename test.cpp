#include "digit.h"
#include "animal.h"

int main()
{
    MyDigit a(4), b(3.3);
    MyDigit resultAdd = a + b;
    std::cout << resultAdd;
    MyDigit resultSub = a - b;
    std::cout << resultSub;
    MyDigit resultMul = a * b;
    std::cout << resultMul;
    MyDigit resultDiv = a / b;
    std::cout << resultDiv;
    MyDigit resultPow = a ^ b;
    std::cout << resultPow;
    ++a;
    std::cout << a;
    --b;
    std::cout << b;
    a += b;
    std::cout << a;
    a.setVal(5);
    a -= b;
    std::cout << a;
    a.setVal(5);
    a *= b;
    std::cout << a;
    a.setVal(5);
    a /= b;
    std::cout << a;
    a.setVal(5);
    int c = 10;
    std::cout << c + a;
    MyDigit d;
    std::cout << d;
    std::cout << a;

    Cow cow1;
    Cow cow2;
    Chicken ch1;
    Chicken ch2;
    Animal anim1;
    Animal anim2;
    std::cout << cow1;
    std::cout << cow2;
    std::cout << ch1;
    std::cout << ch2;
    std::cout << anim1;
    std::cout << anim2;
}