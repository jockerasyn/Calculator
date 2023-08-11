#ifndef ANIMALPARSER_H_
#define ANIMALPARSER_H_
#include <vector>
#include <string>
#include "cow.h"
#include "chicken.h"
#include "animal.h"
#include <cstdio>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filewritestream.h"
#include "parsingError.h"
#include <fstream>

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
    void parsewriter(const std::vector<Animal *> &animals, const char *path);
};
#endif