#include "animalfarm.h"
#include "animalparser.h"

AnimalParser::AnimalParser() {}
Cow AnimalParser::parseCow(const rapidjson::Value &d)
{
    return Cow(d["name"].GetString(), d["weight"].GetDouble(), d["runspeed"].GetDouble());
}
Chicken AnimalParser::parseChicken(const rapidjson::Value &d)
{
    return Chicken(d["name"].GetString(), d["weight"].GetDouble(), d["flyspeed"].GetDouble());
}
AnimalFarm AnimalParser::parse(const char *path)
{
    rapidjson::Document Doc;
    AnimalFarm Animals;
    char rbuff[65536];

    FILE *file = fopen(path, "rb");
    rapidjson::FileReadStream rfile(file, rbuff, sizeof(rbuff));
    Doc.ParseStream(rfile);
    fclose(file);
    std::string cow = "cow";
    std::string ch = "chicken";
    for (auto const &p : Doc["animals"].GetArray())
    {
        if (p["species"].GetString() == cow)
            Animals.addAnimal(this->parseCow(p));
        if (p["species"].GetString() == ch)
            Animals.addAnimal(this->parseChicken(p));
    }
    return Animals;
}