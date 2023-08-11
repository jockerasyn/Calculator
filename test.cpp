#include <vector>
#include <iostream>
#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"

int ReadFile(const std::string path, AnimalFarm &animals);
int SaveFile(const std::string path, AnimalFarm &animals);
int AddCowToFarm(AnimalFarm &animals, const std::string name, const double weight, const double runspeed);
int AddChickenToFarm(AnimalFarm &animals, const std::string name, const double weight, const double flyspeed);

int main()
{
    std::string path;
    AnimalFarm animals;
    ParseError err;

    // json_files/example2.json  <--- correct file path
    // std::cout << "Enter path: ";
    // std::cin >> path;

    AnimalFarm an;
    ReadFile("json_files/example2.json", an);
    AddCowToFarm(an, "tester1", 600, 10);
    AddChickenToFarm(an, "tester2", 1, 100);
    SaveFile("json_files/example5.json", an);

    std::cout << std::endl
              << "success" << std::endl
              << std::endl;
}

int ReadFile(std::string path, AnimalFarm &animals)
{
    ParseError err;
    while (true)
    {
        if (path == "exit")
        {
            std::cout << "File reading ended with EXIT status";
            return 0;
        }
        else
        {
            err = animals.loadFromJson(path.c_str());
            switch (err)
            {
            case NoError:
                std::cout << "File read succesfuly" << std::endl;
                return 0;
                break;
            case FileNotExist:
                std::cout << "Enter correct path: ";
                std::cin >> path;
                // path = "json_files/example2.json";
                // std::cout << path << std::endl;
                break;
            case IncorrectFormat:
                std::cout << "Enter path to correct file: ";
                std::cin >> path;
                // path = "json_files/example21.json";
                // std::cout << path << std::endl;
                break;
            default:
                std::cout << "Unknown Error";
                exit(0);
            }
        }
    }
    return 0;
}
int SaveFile(std::string path, AnimalFarm &animals)
{
    ParseError err;
    while (true)
    {
        err = animals.storeToJson(path.c_str());
        switch (err)
        {
        case NoError:
            std::cout << "Farm was saved successfully" << std::endl;
            return 0;
        case WritingError:
            std::cout << "Something went wrong during saving" << std::endl;
            return -1;
        case DirrNotExist:
            std::cout << "Enter path to correct file: ";
            std::cin >> path;
            break;
        case EmptyFarm:
            std::cout << "Farm is empty (add some animals before saving)" << std::endl;
            return -1;
        default:
            std::cout << "Unknown Error";
            exit(0);
        }
    }
    return 0;
}
int AddCowToFarm(AnimalFarm &animals, const std::string name, const double weight, const double runspeed)
{
    animals.addAnimal(new Cow(name, weight, runspeed));
    return 0;
}
int AddChickenToFarm(AnimalFarm &animals, const std::string name, const double weight, const double flyspeed)
{
    animals.addAnimal(new Chicken(name, weight, flyspeed));
    return 0;
}