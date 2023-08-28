#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include <atomic>
#include <functional>

#include "Threads/threadpool.h"

int example2(int a, int b)
{
    return b + a;
}

int main()
{
    ThreadPool mypool(10);
    std::vector<std::future<int>> result;
    for (int i = 0; i < 200; i++)
    {
        std::packaged_task<int()> task(std::bind(example2, 7, 77));
        result.push_back(task.get_future());
        mypool.AddTask(std::move(task));
    }
    for (auto &f : result)
    {
        if (f.valid())
        {
            f.wait();
            std::cout << f.get() << " ";
        }
    }
    return 0;
}

/*
void example_function()
{
    std::cout << "ble"
              << "bla"
              << "blu" << std::endl;
}

void task_bind()
{
    std::queue<std::packaged_task<int()>> q;
    std::atomic_int atom;

    std::packaged_task<int()> task(std::bind(example2, 2, 4));
    std::future<int> result = task.get_future();
    {
        q.push(std::move(task));

        auto extask = std::move(q.front());
        q.pop();

        extask();
        std::cout << "task_bind: " << result.get() << '\n';
    }
}*/