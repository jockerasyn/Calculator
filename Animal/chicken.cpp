#include "chicken.h"

Chicken::Chicken() : Animal() {}
Chicken::Chicken(std::string name, double weight, double flyspeed) : Animal(name, weight)
{
    FlySpeed = flyspeed;
}
int Chicken::setFlySpeed(const double &fs)
{
    FlySpeed = fs;
    return 0;
}
double Chicken::getFlySpeed() const
{
    return FlySpeed;
}
std::ostream &operator<<(std::ostream &print, const Chicken &obj)
{
    print << "chicken do Yare Yare Daze" << std::endl
          << "name:" << obj.Name << std::endl
          << "weight:" << obj.Weight << std::endl
          << "fly speed:" << obj.FlySpeed << std::endl;
    return print;
}