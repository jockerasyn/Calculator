#include "animalfarm.h"
#include "animalparser.h"

AnimalFarm::AnimalFarm() {}
AnimalFarm::AnimalFarm(std::vector<Animal *> animals)
{
    Animals = animals;
}
AnimalFarm::~AnimalFarm()
{
}
int AnimalFarm::loadFromJson(const char *path)
{
    AnimalParser *parser;
    AnimalFarm af = parser->parse(path);
    Animals = af.Animals;
    return 0;
}
// int AnimalFarm::storeToJson(const char *path)
// {
//     return 0;
// }
std::vector<Cow> AnimalFarm::getCows() const
{
    Cow *pcow;
    std::vector<Cow> cows;
    for (auto const &p : Animals)
    {
        if (dynamic_cast<Cow *>(p))
        {
            pcow = dynamic_cast<Cow *>(p);
            cows.push_back(pcow->getCow());
        }
    }
    return cows;
}
std::vector<Chicken> AnimalFarm::getChickens() const
{
    Chicken *pchicken;
    std::vector<Chicken> chickens;
    for (int i = 0; i < Animals.size(); i++)
    {
        if (dynamic_cast<Chicken *>(Animals[i]))
        {
            pchicken = dynamic_cast<Chicken *>(Animals[i]);
            chickens.push_back(pchicken->getChicken());
        }
    }
    return chickens;
}
void AnimalFarm::addAnimal(Cow *cow)
{
    Animals.push_back(cow);
}
void AnimalFarm::addAnimal(Chicken *chicken)
{
    Animals.push_back(chicken);
}
