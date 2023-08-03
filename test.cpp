#include <vector>
#include <iostream>
#include "Animal/animalfarm.h"
#include "include/rapidjson/prettywriter.h"
#include "include/rapidjson/writer.h"
#include "Animal/parsingError.h"

int main()
{
    std::string path;
    AnimalFarm animals;
    parseError err;

    std::cout << "Enter path: ";
    // std::cin >> path;
    path = "json_files/example1.json";
    std::cout << path << std::endl;

    while (true)
    {
        // json_files/example2.json  <--- correct file path
        err = animals.loadFromJson(path.c_str());
        switch (err)
        {
        case NoError:
            animals.addAnimal(new Cow("cow new", 100, 30));
            animals.addAnimal(new Chicken("chicken new", 10, 2));
            animals.addAnimal(new Chicken("chicken nugget", 12, 4));
            animals.addAnimal(new Chicken("food", 14, 7));
            animals.addAnimal(new Cow("bigger food", 102, 32));
            animals.addAnimal(new Cow("cow new2", 100, 30));
            animals.addAnimal(new Chicken("chicken new2", 10, 2));
            animals.addAnimal(new Chicken("chicken nugget2", 12, 4));
            animals.addAnimal(new Chicken("food2", 14, 7));
            animals.addAnimal(new Cow("bigger food2", 102, 32));
            animals.storeToJson("json_files/example3.json");
            // ...
            return 0;
        case FileNotExist:
            std::cout << "Enter correct path: ";
            // std::cin >> path;
            path = "json_files/example2.json";
            std::cout << path << std::endl;
            break;
        case IncorrectFormat:
            std::cout << "Enter path to correct file: ";
            // std::cin >> path;
            path = "json_files/example21.json";
            std::cout << path << std::endl;
            break;
        default:
            return -1;
        }
    }

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
