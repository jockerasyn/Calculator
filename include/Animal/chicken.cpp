#include "chicken.h"

Chicken::Chicken() : Animal() {}
Chicken::Chicken(std::string name, double weight, double flyspeed) : Animal(name, weight)
{
    FlySpeed = flyspeed;
}
Chicken::~Chicken() {}
int Chicken::setFlySpeed(const double &fs)
{
    FlySpeed = fs;
    return 0;
}
double Chicken::getFlySpeed() const
{
    return FlySpeed;
}
Chicken Chicken::getChicken() const
{
    return *this;
}
std::ostream &operator<<(std::ostream &print, const Chicken &obj)
{
    print << "name:" << obj.Name << std::endl
          << "weight:" << obj.Weight << std::endl
          << "fly speed:" << obj.FlySpeed << std::endl;
    return print;
}

std::string Chicken::Serialize() const
{
    std::stringstream ss;
    std::string string;
    ss << "{\"species\":\"chicken\",\"name\":\""
       << Name.c_str()
       << "\",\"weight\":"
       << Weight
       << ",\"flyspeed\":"
       << FlySpeed
       << "}";
    string = ss.str();
    return string;
}