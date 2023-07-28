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
    rapidjson::FileReadStream rfile(file, rbuff, sizeof(rbuff));
    Doc.ParseStream(rfile);
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
int AnimalParser::parsewriter(const std::vector<Animal *> animals, const char *path)
{
    rapidjson::Document doc;
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    Cow *cow;
    Chicken *chicken;

    writer.StartObject();
    writer.String("animals");
    writer.StartArray();
    for (auto const &p : animals)
    {
        if (dynamic_cast<Cow *>(p))
        {
            cow = dynamic_cast<Cow *>(p);
            // writer.StartObject();
            // writer.String("species");
            // writer.String("cow");
            // writer.String("name");
            // writer.String(cow->getName().c_str());
            // writer.String("weight");
            // writer.Double(cow->getWeight());
            // writer.String("runspeed");
            // writer.Double(cow->getRunSpeed());
            // writer.EndObject();
            cow->Serialize(writer);
        }
        if (dynamic_cast<Chicken *>(p))
        {
            chicken = dynamic_cast<Chicken *>(p);
            // writer.StartObject();
            // writer.String("species");
            // writer.String("chicken");
            // writer.String("name");
            // writer.String(chicken->getName().c_str());
            // writer.String("weight");
            // writer.Double(chicken->getWeight());
            // writer.String("flyspeed");
            // writer.Double(chicken->getFlySpeed());
            // writer.EndObject();
            chicken->Serialize(writer);
        }
    }
    writer.EndArray();
    writer.EndObject();
    doc.Parse(sb.GetString());

    FILE *fp = fopen(path, "wb");
    char writeBuffer[65536];
    rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    rapidjson::Writer<rapidjson::FileWriteStream> fwriter(os);
    doc.Accept(fwriter);
    fclose(fp);
    return 0;
}