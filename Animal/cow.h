#ifndef COW_H_
#define COW_H_
#include "animal.h"

class Cow : public Animal
{
private:
    double RunSpeed;

public:
    Cow();
    Cow(std::string name, double weight, double runspeed);
    int setRunSpeed(const double &rs);
    double getRunSpeed() const;
    friend std::ostream &operator<<(std::ostream &print, const Cow &obj);
};
#endif