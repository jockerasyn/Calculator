#include "threadpool.h"

void ThreadPool::LoopForTP()
{
    while (true)
    {
        std::packaged_task<int()> task;
        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return condition_wait || finish_searching_for_task; });
            condition_wait = false;
        }
        if (finish_searching_for_task && task_queue.empty())
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

ThreadPool::ThreadPool(int number_of_threads) : finish_searching_for_task(false), condition_wait(false)
{
    for (int i = 0; i < number_of_threads; i++)
    {
        pool_of_threads.emplace_back(&ThreadPool::LoopForTP, this);
    }
}

ThreadPool::~ThreadPool()
{
    EndPool();
}

void ThreadPool::AddTask(std::packaged_task<int()> task)
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(std::move(task));
        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            condition_wait = true;
            pool_condition.notify_all();
        }
    }
}

// bool ThreadPool::PoolWorking()
// {
//     std::unique_lock<std::mutex> lock(pool_mutex);
//     return !task_queue.empty();
// }

void ThreadPool::EndPool()
{
    {
        std::unique_lock<std::mutex> lock(condition_mutex);
        finish_searching_for_task = true;
        condition_wait = true;
    }
    pool_condition.notify_all();
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    pool_of_threads.clear();
}
