#include "animalfarm.h"

AnimalFarm::AnimalFarm() {}
AnimalFarm::AnimalFarm(const std::vector<Animal *> &animals)
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
parseError AnimalFarm::loadFromJson(const char *path)
{
    std::vector<Animal *> animals;
    try
    {
        AnimalParser *parser;
        animals = parser->parse(path);
        std::cout << "ERROR := No parse error occured" << std::endl;
        parseError err = NoError;
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
        return err;
    }
    catch (parseError err)
    {
        if (err == FileNotExist)
            std::cout << "ERROR := No such a file or directory" << std::endl;
        else if (err == IncorrectFormat)
            std::cout << "ERROR := Incorrect format of file" << std::endl;
        return err;
    }
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
const std::vector<Cow *> &AnimalFarm::getCows()
{
    return Cows;
}
const std::vector<Chicken *> &AnimalFarm::getChickens()
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
