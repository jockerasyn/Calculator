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
    int loop = 1;

    while (loop)
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
            loop = 0;
            break;
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
        case EmptyFarm:
            std::cout << "Farm is empty";
            loop = 0;
            break;
        default:
            std::cout << "err";
            loop = 0;
            break;
        }

        // // testing writing
        // AnimalFarm animalz;
        // animalz.addAnimal(new Cow("bigger food2", 102, 32));
        // err = animalz.storeToJson("json_files/example4.json");

        // if (err == EmptyFarm)
        // {
        //     std::cout << "Farm2 is empty";
        //     return -1;
        // }
        // else
        // {
        //     std::cout << "farm saved";
        //     return 0;
        // }
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
