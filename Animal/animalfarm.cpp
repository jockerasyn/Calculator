#include "animalfarm.h"

AnimalFarm::AnimalFarm() {}
AnimalFarm::AnimalFarm(std::vector<Animal *> animals)
{
    for (auto const &p : animals)
    {
        if (dynamic_cast<Chicken *>(p))
        {
            Chickens.push_back(dynamic_cast<Chicken *>(p));
        }
        if (dynamic_cast<Cow *>(p))
        {
            Cows.push_back(dynamic_cast<Cow *>(p));
        }
    }
}
AnimalFarm::~AnimalFarm()
{
}
int AnimalFarm::loadFromJson(const char *path)
{
    AnimalParser *parser;
    std::vector<Animal *> animals = parser->parse(path);
    for (auto const &p : animals)
    {
        if (dynamic_cast<Chicken *>(p))
        {
            Chickens.push_back(dynamic_cast<Chicken *>(p));
        }
        if (dynamic_cast<Cow *>(p))
        {
            Cows.push_back(dynamic_cast<Cow *>(p));
        }
    }
    return 0;
}
int AnimalFarm::storeToJson(const char *path)
{
    AnimalParser *parser;
    std::vector<Animal *> animals;
    for (auto const &p : Cows)
        animals.push_back(p);
    for (auto const &p : Chickens)
        animals.push_back(p);
    parser->parsewriter(animals, path);
    return 0;
}
std::vector<Cow *> AnimalFarm::getCows() const
{
    return Cows;
}
std::vector<Chicken *> AnimalFarm::getChickens() const
{
    return Chickens;
}
void AnimalFarm::addAnimal(Cow *cow)
{
    Cows.push_back(cow);
}
void AnimalFarm::addAnimal(Chicken *chicken)
{
    Chickens.push_back(chicken);
}
