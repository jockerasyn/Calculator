#include <iostream>
#include <string>
#include <cmath>
#include "header.cpp"

int main()
{
    BetterCalc a(4), b(3.3);
    BetterCalc resultAdd = a + b;
    std::cout << resultAdd;
    BetterCalc resultSub = a - b;
    std::cout << resultSub;
    BetterCalc resultMul = a * b;
    std::cout << resultMul;
    BetterCalc resultDiv = a / b;
    std::cout << resultDiv;
    BetterCalc resultPow = a ^ b;
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
    BetterCalc d;
    std::cout << d;
    std::cout << a;
}