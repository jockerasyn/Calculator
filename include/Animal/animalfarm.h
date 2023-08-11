#ifndef ANIMALFARM_H_
#define ANIMALFARM_H_ANIMALFARM_H_
#include "animal.h"
#include "cow.h"
#include "chicken.h"
#include <vector>
#include <string>
#include "animalparser.h"
#include "parsingError.h"

class AnimalFarm
{
private:
    std::vector<Cow *> Cows;
    std::vector<Chicken *> Chickens;

public:
    AnimalFarm();
    AnimalFarm(const std::vector<Animal *> &animals);
    ~AnimalFarm();
    ParseError loadFromJson(const char *path);
    ParseError storeToJson(const char *path);
    const std::vector<Cow *> &getCows();
    const std::vector<Chicken *> &getChickens();
    void addAnimal(Cow *cow);
    void addAnimal(Chicken *chicken);
};
#endif