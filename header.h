#pragma once
#include <iostream>
#include <cmath>

class MyDigit
{
protected:
    float Digit;

public:
    MyDigit() : Digit(0) {}
    MyDigit(float val) : Digit(val) {}
    MyDigit operator+(const MyDigit &obj)
    {
        return Digit + obj.Digit;
    }
    MyDigit operator-(const MyDigit &obj)
    {
        return Digit - obj.Digit;
    }
    MyDigit operator*(const MyDigit &obj)
    {
        return Digit * obj.Digit;
    }
    MyDigit operator/(const MyDigit &obj)
    {
        return Digit / obj.Digit;
    }
    MyDigit operator^(const MyDigit &obj)
    {
        return pow(Digit, obj.Digit);
    }
    MyDigit &operator+=(const MyDigit &obj)
    {
        Digit = Digit + obj.Digit;
        return *this;
    }
    MyDigit &operator-=(const MyDigit &obj)
    {
        Digit = Digit - obj.Digit;
        return *this;
    }
    MyDigit &operator*=(const MyDigit &obj)
    {
        Digit = Digit * obj.Digit;
        return *this;
    }
    MyDigit &operator/=(const MyDigit &obj)
    {
        Digit = Digit / obj.Digit;
        return *this;
    }
    MyDigit operator+(const int &val)
    {
        return Digit + val;
    }
    MyDigit operator-(const int &val)
    {
        return Digit - val;
    }
    MyDigit operator*(const int &val)
    {
        return Digit * val;
    }
    MyDigit operator/(const int &val)
    {
        return Digit / val;
    }
    MyDigit &operator+=(const int &val)
    {
        Digit = Digit + val;
        return *this;
    }
    MyDigit &operator-=(const int &val)
    {
        Digit = Digit - val;
        return *this;
    }
    MyDigit &operator*=(const int &val)
    {
        Digit = Digit * val;
        return *this;
    }
    MyDigit &operator/=(const int &val)
    {
        Digit = Digit / val;
        return *this;
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
    int setVal(float val)
    {
        Digit = val;
        return 0;
    }
    friend MyDigit operator+(const int &val, const MyDigit &obj);
    friend MyDigit operator-(const int &val, const MyDigit &obj);
    friend MyDigit operator*(const int &val, const MyDigit &obj);
    friend MyDigit operator/(const int &val, const MyDigit &obj);
    friend std::ostream &operator<<(std::ostream &print, const MyDigit &obj);
};

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
std::ostream &operator<<(std::ostream &print, const MyDigit &obj) // friend function
{
    print << "result = " << obj.Digit << std::endl;
    return print;
}