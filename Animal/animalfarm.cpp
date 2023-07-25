#include "animalfarm.h"
#include "animalparser.h"

AnimalFarm::AnimalFarm() {}

int AnimalFarm::loadFromJson(const char *path)
{
    AnimalParser *Parser;
    AnimalFarm af = Parser->parse(path);
    Cows = af.Cows;
    Chickens = af.Chickens;
    return 0;
}
// int AnimalFarm::storeToJson(const char *path)
// {
//     return 0;
// }
std::vector<Cow> AnimalFarm::getCows() const
{
    return Cows;
}
std::vector<Chicken> AnimalFarm::getChickens() const
{
    return Chickens;
}
void AnimalFarm::addAnimal(const Cow &cow)
{
    Cows.push_back(cow);
}
void AnimalFarm::addAnimal(const Chicken &chicken)
{
    Chickens.push_back(chicken);
}
