#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include "Threads/threads.h"

void example_function()
{
    std::cout << "ble"
              << "bla"
              << "blu" << std::endl;
}

main()
{
    ThreadPool mypool(10);
    for (int i = 0; i < 200; i++)
    {
        // std::packaged_task<void()> task(example_function);
        // mypool.AddTask(std::move(task));
        // mypool.AddTask(std::bind(example_function));
        mypool.AddTask(example_function);
    }
    mypool.EndPool();
}