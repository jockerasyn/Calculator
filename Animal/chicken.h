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
};
#endif