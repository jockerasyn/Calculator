#include "threadpool_v.h"

void ThreadPoolV::LoopForTP()
{
    std::packaged_task<int()> task;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return condition_wait.back() || finish_searching_for_task; });
            condition_wait.erase(condition_wait.end());
        }
        if (finish_searching_for_task)
        {
            return;
        }
        {
            std::unique_lock<std::mutex> lock(pool_mutex);
            task = std::move(task_queue.front());
            task_queue.pop();
        }
        task();
    }
}

ThreadPoolV::ThreadPoolV(int number_of_threads) : finish_searching_for_task(false), condition_wait(false)
{
    condition_wait.push_back(false);
    for (int i = 0; i < number_of_threads; i++)
    {
        pool_of_threads.emplace_back(&ThreadPoolV::LoopForTP, this);
    }
}

ThreadPoolV::~ThreadPoolV()
{
    EndPool();
}

void ThreadPoolV::AddTask(std::packaged_task<int()> task)
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(std::move(task));
    }
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        condition_wait.push_back(true);
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
        condition_wait.clear();
    }
    pool_condition.notify_all();
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    std::unique_lock<std::mutex> lock(pool_mutex);
    pool_of_threads.clear();
}
