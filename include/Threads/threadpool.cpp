#include "threadpool.h"

void ThreadPool::LoopForTP()
{
    std::function<void()> task;
    while (true)
    {
        {
            {
                std::unique_lock<std::mutex> lock(condition_mutex);
                pool_condition.wait(lock, [this]
                                    { return !task_queue.empty() || finish_searching_for_task; });
            }
            if (finish_searching_for_task && task_queue.empty())
            {
                return;
            }
            std::unique_lock<std::mutex> lock(pool_mutex);
            task = task_queue.front();
            task_queue.pop();
        }
        task();
    }
}
ThreadPool::ThreadPool(int number_of_threads) : finish_searching_for_task(false)
{
    for (int i = 0; i < number_of_threads; i++)
        pool_of_threads.emplace_back(std::thread(&ThreadPool::LoopForTP, this));
}
ThreadPool::~ThreadPool() {}
void ThreadPool::AddTask(const std::function<void()> &task)
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(task);
    }
    pool_condition.notify_one();
}
bool ThreadPool::PoolWorking()
{
    bool if_busy = false;
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        if_busy = !task_queue.empty();
    }
    return if_busy;
}
void ThreadPool::EndPool()
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        finish_searching_for_task = true;
    }
    pool_condition.notify_all();
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    pool_of_threads.clear();
}