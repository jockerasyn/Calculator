#ifndef _THREAD_H_
#define _THREAD_H_
#include <thread>
#include <future>
#include <array>
#include <iostream>
#include <mutex>
#include <fstream>
#include <string>
#include <sstream>
#include <atomic>
#include <queue>
#include <cassert>
#include <condition_variable>
#include <functional>

extern std::mutex readMutex;

class sum_of_arr_thread
{
public:
    void operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::promise<int> sum_promise)
    {
        int sum = 0;
        for (int i = arrbegin; i < arrend; i++)
            sum += arr[i];
        sum_promise.set_value(sum);
    }
};

class sum_of_arr_atomic
{
public:
    void operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::atomic_int &sum, std::atomic_int &th_info)
    {
        for (int i = arrbegin; i < arrend; i++)
            sum += arr[i];
        th_info += 1;
    }
};

class filereader
{
public:
    void operator()(const char *path)
    {
        std::stringstream sentence;
        std::ifstream readFile(path);
        if (readFile.is_open())
        {
            std::string text;
            while (getline(readFile, text))
                sentence << text;
        }
        std::lock_guard<std::mutex> guard(readMutex);
        std::cout << std::endl
                  << sentence.str() << std::endl;
    }
};

class ThreadPool
{
private:
    std::vector<std::thread> pool_of_threads;
    std::queue<std::function<void()>> task_queue;
    std::mutex pool_mutex;
    std::mutex condition_mutex;
    std::condition_variable pool_condition;
    bool finish_searching_for_task;
    // loop for threads to let them search for tasks
    void LoopForTP()
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

public:
    ThreadPool(int number_of_threads) : finish_searching_for_task(false)
    {
        for (int i = 0; i < number_of_threads; i++)
            pool_of_threads.emplace_back(std::thread(&ThreadPool::LoopForTP, this));
    }
    ~ThreadPool() {}
    void AddTask(const std::function<void()> &task)
    {
        {
            std::unique_lock<std::mutex> lock(pool_mutex);
            task_queue.push(task);
        }
        pool_condition.notify_one();
    }
    bool PoolWorking()
    {
        bool if_busy = false;
        {
            std::unique_lock<std::mutex> lock(pool_mutex);
            bool poolbif_busyusy = !task_queue.empty();
        }
        return if_busy;
    }
    void EndPool()
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
};
#endif
