#include "threadpool.h"

void ThreadPool::LoopForTP()
{
    std::packaged_task<int()> task;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return condition_wait || finish_searching_for_task; });
            condition_wait = false;
            adp = false;
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

ThreadPool::ThreadPool(int number_of_threads) : finish_searching_for_task(false), condition_wait(false), adp(false)
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
    while (adp)
    {
    }
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(std::move(task));
    }
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        condition_wait = true;
        adp = true;
    }
    pool_condition.notify_one();
}

bool ThreadPool::PoolWorking()
{
    std::unique_lock<std::mutex> lock(pool_mutex);
    return !task_queue.empty();
}

void ThreadPool::EndPool()
{
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        finish_searching_for_task = true;
    }
    pool_condition.notify_all();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1));
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    std::unique_lock<std::mutex> lock(pool_mutex);
    pool_of_threads.clear();
}
