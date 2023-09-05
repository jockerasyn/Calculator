#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include "Threads/threadpool_v.h"
#include <iostream>
#include <ctime>

int example1(int a, int b);
int example2(int a, int b);
int example3(int a, int b);
void threadpool_with_p_task();

int main()
{
    time_t timestart, timeend;
    time(&timestart);
    threadpool_with_p_task();
    time(&timeend);
    std::cout << "It took " << difftime(timeend, timestart) << " second(s)." << std::endl;
    return 0;
}

void threadpool_with_p_task()
{
    ThreadPoolV mypool(10);
    std::cout << "\nthreadpool with packaged_task begun work\n\n";
    std::vector<std::future<int>> result;
    for (int i = 0; i < 200; i++)
    {
        std::packaged_task<int()> task(std::bind(example1, 7, 77));
        result.push_back(task.get_future());
        mypool.AddTask(std::move(task));
    }
    // for (int i = 0; i < 100; i++)
    // {
    //     std::packaged_task<int()> task(std::bind(example2, 7, 77));
    //     result.push_back(task.get_future());
    //     mypool.AddTask(std::move(task));
    // }
    // for (int i = 0; i < 50; i++)
    // {
    //     std::packaged_task<int()> task(std::bind(example3, 7, 77));
    //     result.push_back(task.get_future());
    //     mypool.AddTask(std::move(task));
    // }
    while (mypool.PoolWorking())
    {
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i].get() << "\n";
    }
    mypool.EndPool();
    std::cout << "\n\nthreadpool with packaged_task finished work\n\n";
}

int example1(int a, int b)
{
    return b + a;
}

int example2(int a, int b)
{
    return b * a;
}

int example3(int a, int b)
{
    return b - a;
}