#include <vector>
#include "Animal/animalfarm.h"

int main()
{
    AnimalFarm animals;
    animals.loadFromJson("json_files/example2.json");

    std::vector<Cow> cows = animals.getCows();
    std::vector<Chicken> chickens = animals.getChickens();
    // presentation
    for (auto const &p : cows)
        std::cout << p << std::endl;
    for (auto const &p : chickens)
        std::cout << p << std::endl;
}
