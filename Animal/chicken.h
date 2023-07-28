#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "animal.h"

class Chicken : public Animal
{
private:
    double FlySpeed;

public:
    Chicken();
    Chicken(std::string name, double weight, double flyspeed);
    virtual ~Chicken();
    int setFlySpeed(const double &rs);
    double getFlySpeed() const;
    Chicken getChicken() const;
    friend std::ostream &operator<<(std::ostream &print, const Chicken &obj);
    friend std::ostream &operator<<(std::ostream &print, const Chicken *obj);

    std::string Serialize() const
    {
        rapidjson::StringBuffer sb;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
        writer.StartObject();
        writer.String("species");
        writer.String("chicken");
        writer.String("name");
        writer.String(Name.c_str());
        writer.String("weight");
        writer.Double(Weight);
        writer.String("flyspeed");
        writer.Double(FlySpeed);
        writer.EndObject();

        return sb.GetString();
    }
};
#endif