#include <iostream>
#include <string>
#include <cmath>

class BetterCalc
{
protected:
    float Digit;

public:
    BetterCalc() : Digit(0) {}
    BetterCalc(float val) : Digit(val) {}
    BetterCalc operator+(const BetterCalc &obj)
    {
        return Digit + obj.Digit;
    }
    BetterCalc operator-(const BetterCalc &obj)
    {
        return Digit - obj.Digit;
    }
    BetterCalc operator*(const BetterCalc &obj)
    {
        return Digit * obj.Digit;
    }
    BetterCalc operator/(const BetterCalc &obj)
    {
        return Digit / obj.Digit;
    }
    BetterCalc operator^(const BetterCalc &obj)
    {
        return pow(Digit, obj.Digit);
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
        return Digit + val;
    }
    BetterCalc operator-(const int &val)
    {
        return Digit - val;
    }
    BetterCalc operator*(const int &val)
    {
        return Digit * val;
    }
    BetterCalc operator/(const int &val)
    {
        return Digit / val;
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
    friend BetterCalc operator-(const int &val, const BetterCalc &obj);
    friend BetterCalc operator*(const int &val, const BetterCalc &obj);
    friend BetterCalc operator/(const int &val, const BetterCalc &obj);
    friend std::ostream &operator<<(std::ostream &print, const BetterCalc &obj);
};

BetterCalc operator+(const int &val, const BetterCalc &obj)
{
    return val + obj.Digit;
}
BetterCalc operator-(const int &val, const BetterCalc &obj)
{
    return val - obj.Digit;
}
BetterCalc operator*(const int &val, const BetterCalc &obj)
{
    return val * obj.Digit;
}
BetterCalc operator/(const int &val, const BetterCalc &obj)
{
    return val / obj.Digit;
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
    BetterCalc d;
    std::cout << d;
    std::cout << a;
}