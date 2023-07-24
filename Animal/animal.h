#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/filereadstream.h"

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

class AnimalParser
{
private:
    rapidjson::Document Doc;

public:
    AnimalParser();
    ~AnimalParser();
    std::vector<Animal> parse(const char *path);
};
#endif