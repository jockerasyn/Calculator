#ifndef ANIMALPARSER_H_
#define ANIMALPARSER_H_
#include <vector>
#include <string>
#include "animalfarm.h"
#include "cow.h"
#include "chicken.h"
#include "animal.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/filereadstream.h"

class AnimalFarm;
class AnimalParser
{
private:
    Cow *parseCow(const rapidjson::Value &d);
    Chicken *parseChicken(const rapidjson::Value &d);

public:
    AnimalParser();
    AnimalFarm parse(const char *path);
};
#endif