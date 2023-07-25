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
    int setFlySpeed(const double &rs);
    double getFlySpeed() const;
    friend std::ostream &operator<<(std::ostream &print, const Chicken &obj);
};
#endif