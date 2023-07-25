#include <vector>
#include "Animal/animalfarm.h"

int main()
{
    // AnimalParser parser;
    // AnimalFarm aaaa;
    // std::vector<Animal> animals;
    // parser.parse("json_files/example1.json");

    // // presentation
    // for (auto i = animals.begin(); i != animals.end(); ++i)
    //     std::cout << *i << std::endl;

    // Cow cow1("cow1", 100, 50);
    // std::cout << cow1 << std::endl;
    // Animal *an1 = &cow1;
    // std::cout << an1 << std::endl;
    // Chicken ch1("chicken1", 15, 5);
    // std::cout << ch1 << std::endl;
    // Animal *an2 = &ch1;
    // std::cout << an2 << std::endl;

    AnimalFarm animals;
    animals.loadFromJson("json_files/example2.json");

    std::vector<Cow> cows = animals.getCows();
    // presentation
    for (auto i = cows.begin(); i != cows.end(); ++i)
        std::cout << *i << std::endl;
}
