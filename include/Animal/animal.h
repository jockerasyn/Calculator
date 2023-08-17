#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include <cstdint>
#include <string>
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include <sstream>

class Animal
{
protected:
    std::string Name;
    double Weight;

public:
    Animal();
    Animal(std::string name, double weight);
    virtual ~Animal();
    int setName(const std::string &name);
    int setWeight(const int &weight);
    std::string getName() const;
    double getWeight() const;
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);

    // testing purposes only
    virtual std::string Serialize() const;
};
#endif