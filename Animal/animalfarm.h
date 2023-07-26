#ifndef ANIMALFARM_H_
#define ANIMALFARM_H_
#include "animal.h"
#include "cow.h"
#include "chicken.h"
#include <vector>
#include <string>

class AnimalParser;
class AnimalFarm
{
private:
    std::vector<Animal *> Animals;

public:
    AnimalFarm();
    AnimalFarm(std::vector<Animal *> animals);
    ~AnimalFarm();
    int loadFromJson(const char *path);
    // int storeToJson(const char *path);
    std::vector<Cow> getCows() const;
    std::vector<Chicken> getChickens() const;
    void addAnimal(Cow *cow);
    void addAnimal(Chicken *chicken);
};
#endif