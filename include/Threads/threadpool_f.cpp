#include "threadpool_f.h"

void ThreadPool_F::LoopForTP()
{
    while (true)
    {
        std::function<int()> task;

        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return adpv || finish_searching_for_task; });
            adpv = false;
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

        if (task)
        {
            int result = task();
            {
                std::lock_guard<std::mutex> lock(result_mutex);
                results.push_back(result);
            }
        }
    }
}

ThreadPool_F::ThreadPool_F(int number_of_threads) : finish_searching_for_task(false)
{
    for (int i = 0; i < number_of_threads; i++)
    {
        pool_of_threads.emplace_back(&ThreadPool_F::LoopForTP, this);
    }
}

ThreadPool_F::~ThreadPool_F()
{
    EndPool();
    results.clear();
}

void ThreadPool_F::AddTask(std::function<int()> task)
{
    {
        std::unique_lock<std::mutex> lock(pool_mutex);
        task_queue.push(std::move(task));
    }
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        adpv = true;
    }
    pool_condition.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

bool ThreadPool_F::PoolWorking()
{
    std::unique_lock<std::mutex> lock(pool_mutex);
    return !task_queue.empty();
}

void ThreadPool_F::EndPool()
{
    {
        std::lock_guard<std::mutex> lock(condition_mutex);
        finish_searching_for_task = true;
    }
    pool_condition.notify_all();
    for (std::thread &thread : pool_of_threads)
    {
        thread.join();
    }
    pool_of_threads.clear();
}

const std::vector<int> &ThreadPool_F::GetResults()
{
    std::lock_guard<std::mutex> lock(result_mutex);
    return results;
}
