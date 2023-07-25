#include "animalparser.h"

AnimalParser::AnimalParser() {}
AnimalParser::~AnimalParser() {}

std::vector<Animal> AnimalParser::parse(const char *path)
{
    rapidjson::Document Doc;
    std::vector<Animal> Animals;
    char rbuff[65536];

    FILE *file = fopen(path, "rb");
    rapidjson::FileReadStream rfile(file, rbuff, sizeof(rbuff));
    Doc.ParseStream(rfile);
    fclose(file);
    for (auto const &p : Doc["animals"].GetArray())
        Animals.push_back(Animal(p["name"].GetString(), p["weight"].GetDouble()));
    return Animals;
}