#include "animalparser.h"

AnimalParser::AnimalParser() {}
AnimalParser::~AnimalParser() {}
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
std::vector<Animal *> AnimalParser::parse(const char *path)
{

    rapidjson::Document Doc;
    char rbuff[65536];
    std::vector<Animal *> animals;
    FILE *file = fopen(path, "rb");
    ParseError err;

    if (!(file))
    {
        file = nullptr;
        throw err = FileNotExist;
    }
    else
    {
        rapidjson::FileReadStream rfile(file, rbuff, sizeof(rbuff));
        Doc.ParseStream(rfile);
        if (Doc.HasParseError())
            throw err = IncorrectFormat;

        fclose(file);
        const std::string cow = "cow";
        const std::string chi = "chicken";
        for (auto const &p : Doc["animals"].GetArray())
        {
            if (p["species"].GetString() == cow)
            {
                animals.push_back(parseCow(p));
            }
            if (p["species"].GetString() == chi)
            {
                animals.push_back(parseChicken(p));
            }
        }
        return animals;
    }
}
void AnimalParser::parsewriter(const std::vector<Animal *> &animals, const char *path)
{
    ParseError err;
    rapidjson::Document doc;
    std::string result = "{\"animals\":[";
    for (auto const *p : animals)
    {
        result = result + p->Serialize() + ",";
    }
    result.erase(result.end() - 1, result.end());
    result = result + "]}";
    // std::cout << result << std::endl;
    doc.Parse(result.c_str());
    if (doc.HasParseError())
        throw err = WritingError;
    else
    {
        FILE *fp = fopen(path, "wb");

        if (!(fp))
        {
            fp = nullptr;
            throw err = DirrNotExist;
        }
        char writeBuffer[65536];
        rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        rapidjson::Writer<rapidjson::FileWriteStream> fwriter(os);
        doc.Accept(fwriter);
        if (!fwriter.IsComplete())
        {
            fclose(fp);
            throw err = FileWriteError;
        }
        fclose(fp);
    }
}