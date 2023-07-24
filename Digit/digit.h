#ifndef DIGIT_H_
#define Digit_H_
#include <iostream>
#include <cmath>
#include <cstdint>

class MyDigit
{
protected:
    float_t Digit;

public:
    MyDigit();
    MyDigit(float_t val);
    MyDigit operator+(const MyDigit &obj);
    MyDigit operator-(const MyDigit &obj);
    MyDigit operator*(const MyDigit &obj);
    MyDigit operator/(const MyDigit &obj);
    MyDigit operator^(const MyDigit &obj);
    MyDigit &operator+=(const MyDigit &obj);
    MyDigit &operator-=(const MyDigit &obj);
    MyDigit &operator*=(const MyDigit &obj);
    MyDigit &operator/=(const MyDigit &obj);
    MyDigit operator+(const int &val);
    MyDigit operator-(const int &val);
    MyDigit operator*(const int &val);
    MyDigit operator/(const int &val);
    MyDigit &operator+=(const int &val);
    MyDigit &operator-=(const int &val);
    MyDigit &operator*=(const int &val);
    MyDigit &operator/=(const int &val);
    void operator++();
    void operator--();
    float getVal() const;
    int setVal(float_t val);
    friend MyDigit operator+(const int &val, const MyDigit &obj);
    friend MyDigit operator-(const int &val, const MyDigit &obj);
    friend MyDigit operator*(const int &val, const MyDigit &obj);
    friend MyDigit operator/(const int &val, const MyDigit &obj);
    friend std::ostream &operator<<(std::ostream &print, const MyDigit &obj);
};
#endif