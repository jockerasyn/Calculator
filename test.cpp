#include <vector>
#include "Animal/animalfarm.h"
#include "include/rapidjson/prettywriter.h"
#include "include/rapidjson/writer.h"

int main()
{
    AnimalFarm animals;
    animals.loadFromJson("json_files/example2.json");

    animals.addAnimal(new Cow("cow new", 100, 30));
    animals.addAnimal(new Chicken("chicken new", 10, 2));

    animals.storeToJson("json_files/example3.json");

    // std::vector<Cow *> cows = animals.getCows();
    // std::vector<Chicken *> chickens = animals.getChickens();
    // // presentation
    // for (auto const &p : cows)
    //     std::cout << p << std::endl;
    // for (auto const &p : chickens)
    //     std::cout << p << std::endl;

    // AnimalParser parser;
    // std::vector<Animal *> an = parser.parse("json_files/example2.json");
    // an.push_back(new Cow("cow222 new", 122, 31));
    // parser.parsewriter(an, "json_files/example2.json");
}
