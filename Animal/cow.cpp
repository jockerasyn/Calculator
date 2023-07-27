#include "cow.h"

Cow::Cow() : Animal() {}
Cow::Cow(std::string name, double weight, double runspeed) : Animal(name, weight)
{
    RunSpeed = runspeed;
}
Cow::~Cow() {}
int Cow::setRunSpeed(const double &rs)
{
    RunSpeed = rs;
    return 0;
}
double Cow::getRunSpeed() const
{
    return RunSpeed;
}
Cow Cow::getCow() const
{
    return *this;
}
std::ostream &operator<<(std::ostream &print, const Cow &obj)
{
    print << "name:" << obj.Name << std::endl
          << "weight:" << obj.Weight << std::endl
          << "run speed:" << obj.RunSpeed << std::endl;
    return print;
}
std::ostream &operator<<(std::ostream &print, const Cow *obj)
{
    print << "name:" << obj->Name << std::endl
          << "weight:" << obj->Weight << std::endl
          << "run speed:" << obj->RunSpeed << std::endl;
    return print;
}