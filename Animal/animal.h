#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include <cstdint>
#include <string>
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/prettywriter.h"

class Animal
{
protected:
    std::string Name;
    double Weight;

public:
    Animal();
    Animal(std::string name, double weight);
    virtual ~Animal();
    int setName(const std::string &name);
    int setWeight(const int &weight);
    std::string getName() const;
    double getWeight() const;
    friend std::ostream &operator<<(std::ostream &print, const Animal &obj);
    friend std::ostream &operator<<(std::ostream &print, const Animal *obj);

    // testing purposes only
    virtual std::string Serialize() const
    {
        rapidjson::StringBuffer sb;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
        writer.String("species");
        writer.String("N/A");
        writer.String("name");
        writer.String(Name.c_str());
        writer.String("weight");
        writer.Double(Weight);
        return sb.GetString();
    }
};
#endif