#include <vector>
#include "Animal/animalfarm.h"

int main()
{
    AnimalFarm animals;
    animals.loadFromJson("json_files/example2.json");

    std::vector<Cow> cows = animals.getCows();
    std::vector<Chicken> chickens = animals.getChickens();
    // presentation
    for (auto i = cows.begin(); i != cows.end(); ++i)
        std::cout << *i << std::endl;
    for (auto const &p : chickens)
        std::cout << p << std::endl;
}
