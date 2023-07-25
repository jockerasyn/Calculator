#include "Animal/animal.h"
#include "Animal/animalparser.h"
#include <vector>

int main()
{
    AnimalParser parser;
    std::vector<Animal> animals = parser.parse("json_files/example1.json");

    // presentation
    for (auto i = animals.begin(); i != animals.end(); ++i)
        std::cout << *i << std::endl;
}
