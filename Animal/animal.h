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
    Animal();
    Animal(std::string name, double weight);
    ~Animal();
    int setName(std::string name);
    int setWeight(int weight);
    std::string getName() const;
    double getWeight() const;
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);
};