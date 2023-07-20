#pragma once
#include <iostream>
#include <cmath>
#include <cstdint>

class MyDigit
{
protected:
    float_t Digit;
    inline static int16_t NEXT_ID = 0;
    int16_t Id;

public:
    MyDigit() : Digit(0), Id(NEXT_ID++) {}
    MyDigit(float_t val) : Digit(val), Id(NEXT_ID++) {}
    int getId()
    {
        return Id;
    }
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
    int setVal(float_t val)
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
std::ostream &operator<<(std::ostream &print, const MyDigit &obj)
{
    print << "result = " << obj.Digit << " ID: " << obj.Id << std::endl;
    return print;
}