#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class BetterCalc
{
private:
    float Digit;

public:
    BetterCalc(float val)
    {
        Digit = val;
    }
    BetterCalc operator+(const BetterCalc &obj)
    {
        BetterCalc temp = Digit + obj.Digit;
        return temp;
    }
    BetterCalc operator-(const BetterCalc &obj)
    {
        BetterCalc temp = Digit - obj.Digit;
        return temp;
    }
    BetterCalc operator*(const BetterCalc &obj)
    {
        BetterCalc temp = Digit * obj.Digit;
        return temp;
    }
    BetterCalc operator/(const BetterCalc &obj)
    {
        BetterCalc temp = Digit / obj.Digit;
        return temp;
    }
    BetterCalc operator^(const BetterCalc &obj)
    {
        BetterCalc temp = pow(Digit, obj.Digit);
        return temp;
    }
    void operator++()
    {
        ++Digit;
    }
    void operator--()
    {
        --Digit;
    }
    float getVal() const
    {
        return Digit;
    }
};

int main()
{
    BetterCalc a(4), b(3.3);
    BetterCalc resultAdd = a + b;
    cout << resultAdd.getVal() << endl;
    BetterCalc resultSub = a - b;
    cout << resultSub.getVal() << endl;
    BetterCalc resultMul = a * b;
    cout << resultMul.getVal() << endl;
    BetterCalc resultDiv = a / b;
    cout << resultDiv.getVal() << endl;
    BetterCalc resultPow = a ^ b;
    cout << resultPow.getVal() << endl;
    ++a;
    --b;
    cout << a.getVal() << " " << b.getVal() << endl;
}

/*
class Calculator
{
private:
    float Number;

public:
    float getNumber()
    {
        return Number;
    }
    void setNumber(float number)
    {
        Number = number;
    }
    void addCalculate(float a, float b)
    {
        Number = a + b;
    }
    void subCalculate(float a, float b)
    {
        Number = a - b;
    }
    void mulCalculate(float a, float b)
    {
        Number = a * b;
    }
    void divCalculate(float a, float b)
    {
        Number = a / b;
    }
    void addNumber(float add)
    {
        Number = Number + add;
    }
    void subNumber(float subtract)
    {
        Number = Number - subtract;
    }
    void mulNumber(float multiplicate)
    {
        Number = Number * multiplicate;
    }
    void divNumber(float divide)
    {
        Number = Number / divide;
    }
    Calculator(int n) : Number(n) {}
};

int main()
{
    Calculator n(2);
    std::cout << "result default = " << n.getNumber() << std::endl;
    n.addCalculate(2, 3);
    std::cout << "result add = " << n.getNumber() << std::endl;
    n.subCalculate(4, 8.2);
    std::cout << "result sub = " << n.getNumber() << std::endl;
    n.divCalculate(3, 2);
    std::cout << "result div = " << n.getNumber() << std::endl;
    n.mulCalculate(4, 8);
    std::cout << "result mul = " << n.getNumber() << std::endl;
    n.setNumber(5.3);
    std::cout << "result set = " << n.getNumber() << std::endl;
    n.addNumber(2);
    std::cout << "result Nadd = " << n.getNumber() << std::endl;
    n.subNumber(6);
    std::cout << "result Nsub = " << n.getNumber() << std::endl;
    n.divNumber(2);
    std::cout << "result Ndiv = " << n.getNumber() << std::endl;
    n.mulNumber(5);
    std::cout << "result Nmul = " << n.getNumber() << std::endl;
}
*/
