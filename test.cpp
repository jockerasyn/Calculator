#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include "Threads/threadpool.h"
#include "Threads/threadpool_f.h"
#include <iostream>

int example2(int a, int b);
int example21(int a);
int example3(int a, int b);
int example4(int a);
int example5(int a);
void threadpool_with_function();

int main()
{
    ThreadPool mypool(10);
    std::vector<std::future<int>> result;
    for (int i = 0; i < 100; i++)
    {
        std::packaged_task<int()> task(std::bind(example2, 7, 77));
        result.push_back(task.get_future());
        mypool.AddTask(std::move(task));
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i].get() << "\n";
    }
    mypool.EndPool();
    return 0;
}

int example2(int a, int b)
{
    return b + a;
}

int example21(int a)
{
    return a;
}

int example3(int a, int b)
{
    return pow(a, b);
}

int example4(int a)
{
    return a;
}

int example5(int a)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return a;
}

void threadpool_with_function()
{
    ThreadPool_F mypool(10);
    for (int i = 0; i < 50; i++)
    {
        std::function<int()> task1 = std::bind(example21, 1);
        std::function<int()> task2 = std::bind(example5, i);
        std::function<int()> task3 = std::bind(example4, 2);
        mypool.AddTask(task1);
        mypool.AddTask(task2);
        mypool.AddTask(task3);
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::vector<int> results = mypool.GetResults();
    for (int &result : results)
    {
        std::cout << "Result: " << result << std::endl;
    }

    mypool.EndPool();
}