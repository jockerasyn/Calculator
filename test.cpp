#include "Digit/digit.h"
#include "Animal/animal.h"
#include <vector>
#include "include/rapidjson/reader.h"

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

    Animal anim1("cow1", 120.4);
    Animal anim2;
    Animal anim3("dolphin", 100);
    std::vector<Animal> animals;
    animals.push_back(anim1);
    animals.push_back(anim2);
    animals.push_back(anim3);
    for (auto i = animals.begin(); i != animals.end(); ++i)
        std::cout << *i;
}