#pragma once
#include <iostream>
#include <cstdint>
#include <string>

class Animal
{
protected:
    std::string Name;
    double Weight;

public:
    Animal() : Name("none"), Weight(0) {}
    Animal(std::string name, double weight) : Name(name), Weight(weight) {}
    int setName(std::string name)
    {
        Name = name;
        return 0;
    }
    int setWeight(int weight)
    {
        Weight = weight;
        return 0;
    }
    std::string getName() const
    {
        return Name;
    }
    double getWeight() const
    {
        return Weight;
    }
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);
};

std::ostream &operator<<(std::ostream &print, const Animal &obj)
{
    print << "'" << obj.Name << "','" << obj.Weight << "'" << std::endl;
    return print;
}