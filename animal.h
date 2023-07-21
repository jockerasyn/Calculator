#pragma once
#include <iostream>
#include <cstdint>
#include <string>

class Animal
{
protected:
    inline static int16_t NEXT_ID;
    int16_t Id;
    std::string Species;

public:
    Animal() : Id(NEXT_ID++) {}
    Animal(std::string species) : Species(species), Id(NEXT_ID++) {}
    std::string printInfo()
    {
        return Species;
    }
    void setSpecies(std::string species)
    {
        Species = species;
    }
    void setID(int id)
    {
        Id = id;
    }
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);
};

std::ostream &operator<<(std::ostream &print, const Animal &obj)
{
    print << "'" << obj.Species << "','" << obj.Id << "'" << std::endl;
    return print;
}

class Cow : public Animal
{
public:
    Cow()
    {
        Species = "cow";
    }
};

class Chicken : public Animal
{
public:
    Chicken()
    {
        Species = "chicken";
    }
};