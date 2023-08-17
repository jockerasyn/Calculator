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
    virtual ~Cow();
    int setRunSpeed(const double &rs);
    double getRunSpeed() const;
    Cow getCow() const;
    friend std::ostream &operator<<(std::ostream &print, const Cow &obj);

    // testing purposes only
    std::string Serialize() const;
};
#endif