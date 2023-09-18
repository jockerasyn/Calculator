#include "threadpool_v.h"

void ThreadPoolV::LoopForTP()
{
    std::packaged_task<int()> task;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return (!task_queue.empty() || finish_searching_for_task); });
        }
        if (finish_searching_for_task)
        {
            return;
        }
        {
            std::unique_lock<std::mutex> lock(pool_mutex);
            if (!task_queue.empty())
            {
                task = std::move(task_queue.front());
                task_queue.pop();
            }
            else
            {
                continue;
            }
        }
        task();
    }
}

ThreadPoolV::ThreadPoolV(int number_of_threads) : finish_searching_for_task(false)
{
    for (int i = 0; i < number_of_threads; i++)
    {
        pool_of_threads.emplace_back(&ThreadPoolV::LoopForTP, this);
    }
}

ThreadPoolV::~ThreadPoolV()
{
    EndPool();
    std::lock_guard<std::mutex> lock(condition_mutex);
}

void ThreadPoolV::AddTask(std::packaged_task<int()> task)
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(std::move(task));
    }
    pool_condition.notify_one();
}

bool ThreadPoolV::PoolWorking()
{
    std::unique_lock<std::mutex> lock(pool_mutex);
    return !task_queue.empty();
}

void ThreadPoolV::EndPool()
{
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        finish_searching_for_task = true;
    }
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        std::queue<std::packaged_task<int()>>().swap(task_queue);
    }
    pool_condition.notify_all();
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    std::unique_lock<std::mutex> lock(pool_mutex);
    pool_of_threads.clear();
}
