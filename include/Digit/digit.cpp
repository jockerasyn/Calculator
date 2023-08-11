#include "digit.h"

MyDigit::MyDigit() : Digit(0) {}
MyDigit::MyDigit(float_t val) : Digit(val) {}
MyDigit MyDigit::operator+(const MyDigit &obj)
{
    return Digit + obj.Digit;
}
MyDigit MyDigit::operator-(const MyDigit &obj)
{
    return Digit - obj.Digit;
}
MyDigit MyDigit::operator*(const MyDigit &obj)
{
    return Digit * obj.Digit;
}
MyDigit MyDigit::operator/(const MyDigit &obj)
{
    return Digit / obj.Digit;
}
MyDigit MyDigit::operator^(const MyDigit &obj)
{
    return pow(Digit, obj.Digit);
}
MyDigit &MyDigit::operator+=(const MyDigit &obj)
{
    Digit = Digit + obj.Digit;
    return *this;
}
MyDigit &MyDigit::operator-=(const MyDigit &obj)
{
    Digit = Digit - obj.Digit;
    return *this;
}
MyDigit &MyDigit::operator*=(const MyDigit &obj)
{
    Digit = Digit * obj.Digit;
    return *this;
}
MyDigit &MyDigit::operator/=(const MyDigit &obj)
{
    Digit = Digit / obj.Digit;
    return *this;
}
MyDigit MyDigit::operator+(const int &val)
{
    return Digit + val;
}
MyDigit MyDigit::operator-(const int &val)
{
    return Digit - val;
}
MyDigit MyDigit::operator*(const int &val)
{
    return Digit * val;
}
MyDigit MyDigit::operator/(const int &val)
{
    return Digit / val;
}
MyDigit &MyDigit::operator+=(const int &val)
{
    Digit = Digit + val;
    return *this;
}
MyDigit &MyDigit::operator-=(const int &val)
{
    Digit = Digit - val;
    return *this;
}
MyDigit &MyDigit::operator*=(const int &val)
{
    Digit = Digit * val;
    return *this;
}
MyDigit &MyDigit::operator/=(const int &val)
{
    Digit = Digit / val;
    return *this;
}
void MyDigit::operator++()
{
    ++Digit;
}
void MyDigit::operator--()
{
    --Digit;
}
float MyDigit::getVal() const
{
    return Digit;
}
int MyDigit::setVal(const float_t &val)
{
    Digit = val;
    return 0;
}

MyDigit operator+(const int &val, const MyDigit &obj)
{
    return val + obj.Digit;
}
MyDigit operator-(const int &val, const MyDigit &obj)
{
    return val - obj.Digit;
}
MyDigit operator*(const int &val, const MyDigit &obj)
{
    return val * obj.Digit;
}
MyDigit operator/(const int &val, const MyDigit &obj)
{
    return val / obj.Digit;
}
std::ostream &operator<<(std::ostream &print, const MyDigit &obj)
{
    print << "result = " << obj.Digit << std::endl;
    return print;
}