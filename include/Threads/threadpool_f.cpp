#include "threadpool_f.h"

void ThreadPool_F::LoopForTP()
{
    while (true)
    {
        std::function<int()> task;

        {
            std::unique_lock<std::mutex> lock(condition_mutex);
            pool_condition.wait(lock, [this]
                                { return !task_queue.empty() || finish_searching_for_task.load(); });
        }

        if (finish_searching_for_task.load() && task_queue.empty())
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
    pool_condition.notify_one();
}

void ThreadPool_F::EndPool()
{
    {
        std::unique_lock<std::mutex> lock(condition_mutex);
        finish_searching_for_task.store(true);
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
