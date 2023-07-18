#include <iostream>
#include <string>
#include <cmath>

class BetterCalc
{
protected:
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
    BetterCalc &operator+=(const BetterCalc &obj)
    {
        Digit = Digit + obj.Digit;
        return *this;
    }
    BetterCalc &operator-=(const BetterCalc &obj)
    {
        Digit = Digit - obj.Digit;
        return *this;
    }
    BetterCalc &operator*=(const BetterCalc &obj)
    {
        Digit = Digit * obj.Digit;
        return *this;
    }
    BetterCalc &operator/=(const BetterCalc &obj)
    {
        Digit = Digit / obj.Digit;
        return *this;
    }
    BetterCalc operator+(const int &val)
    {
        BetterCalc temp = Digit + val;
        return temp;
    }
    BetterCalc operator-(const int &val)
    {
        BetterCalc temp = Digit - val;
        return temp;
    }
    BetterCalc operator*(const int &val)
    {
        BetterCalc temp = Digit * val;
        return temp;
    }
    BetterCalc operator/(const int &val)
    {
        BetterCalc temp = Digit / val;
        return temp;
    }
    BetterCalc &operator+=(const int &val)
    {
        Digit = Digit + val;
        return *this;
    }
    BetterCalc &operator-=(const int &val)
    {
        Digit = Digit - val;
        return *this;
    }
    BetterCalc &operator*=(const int &val)
    {
        Digit = Digit * val;
        return *this;
    }
    BetterCalc &operator/=(const int &val)
    {
        Digit = Digit / val;
        return *this;
    }
    // there can be more copy of ^ this |-|*|/|
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
    int setVal(float val)
    {
        Digit = val;
        return 0;
    }
    friend BetterCalc operator+(const int &val, const BetterCalc &obj);
    friend std::ostream &operator<<(std::ostream &print, const BetterCalc &obj);
};

BetterCalc operator+(const int &val, const BetterCalc &obj)
{
    return val + obj.Digit;
}
std::ostream &operator<<(std::ostream &print, const BetterCalc &obj) // friend function
{
    print << "result = " << obj.Digit << std::endl;
    return print;
}

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
