#include "animal.h"

Animal::Animal() : Name("none"), Weight(0) {}
Animal::Animal(std::string name, double weight) : Name(name), Weight(weight) {}
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
    print << "'" << obj.Name << "','" << obj.Weight << "'" << std::endl;
    return print;
}