#ifndef ANIMAL_H_
#define ANIMAL_H_
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
    int setName(const std::string &name);
    int setWeight(const int &weight);
    std::string getName() const;
    double getWeight() const;
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);
    friend std::ostream &operator<<(std::ostream &print, const Animal *obj);
};
#endif