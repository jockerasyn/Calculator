#ifndef ANIMALPARSER_H_
#define ANIMALPARSER_H_
#include <vector>
#include <string>
#include "cow.h"
#include "chicken.h"
#include "animal.h"
#include <cstdio>
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/filereadstream.h"
#include "../include/rapidjson/prettywriter.h"
#include "../include/rapidjson/filewritestream.h"

class AnimalParser
{
private:
    Cow *parseCow(const rapidjson::Value &d);
    Chicken *parseChicken(const rapidjson::Value &d);

public:
    AnimalParser();
    ~AnimalParser();
    std::vector<Animal *> parse(const char *path);
    // only for testing purposes
    int parsewriter(const std::vector<Animal *> animals, const char *path);
};
#endif