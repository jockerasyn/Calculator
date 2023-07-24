#include "animal.h"

Animal::Animal() : Name("none"), Weight(0) {}
Animal::Animal(std::string name, double weight) : Name(name), Weight(weight) {}
Animal::~Animal() {}
int Animal::setName(std::string name)
{
    Name = name;
    return 0;
}
int Animal::setWeight(int weight)
{
    Weight = weight;
    return 0;
}
std::string Animal::getName() const
{
    return Name;
}
double Animal::getWeight() const
{
    return Weight;
}

std::ostream &operator<<(std::ostream &print, const Animal &obj)
{
    print << "name:" << obj.Name << std::endl
          << "weight:" << obj.Weight << std::endl;
    return print;
}

AnimalParser::AnimalParser() {}
AnimalParser::~AnimalParser() {}

std::vector<Animal> AnimalParser::parse(const char *path)
{
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