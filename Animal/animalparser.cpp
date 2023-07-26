#include "animalfarm.h"
#include "animalparser.h"

AnimalParser::AnimalParser() {}
Cow *AnimalParser::parseCow(const rapidjson::Value &d)
{
    Cow *cow = new Cow(d["name"].GetString(), d["weight"].GetDouble(), d["runspeed"].GetDouble());
    return cow;
}
Chicken *AnimalParser::parseChicken(const rapidjson::Value &d)
{
    Chicken *chicken = new Chicken(d["name"].GetString(), d["weight"].GetDouble(), d["flyspeed"].GetDouble());
    return chicken;
}
AnimalFarm AnimalParser::parse(const char *path)
{
    rapidjson::Document Doc;
    char rbuff[65536];
    AnimalFarm animals;

    FILE *file = fopen(path, "rb");
    rapidjson::FileReadStream rfile(file, rbuff, sizeof(rbuff));
    Doc.ParseStream(rfile);
    fclose(file);
    std::string cow = "cow";
    std::string ch = "chicken";
    for (auto const &p : Doc["animals"].GetArray())
    {
        if (p["species"].GetString() == cow)
        {
            animals.addAnimal(parseCow(p));
        }
        if (p["species"].GetString() == ch)
        {
            animals.addAnimal(parseChicken(p));
        }
    }
    return animals;
}