#include <iostream>

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
    Calculator()
    {
        Number = 0;
    }
};

int main()
{
    Calculator n = Calculator();
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