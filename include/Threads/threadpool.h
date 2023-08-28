#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_
#include <thread>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <cassert>
#include <condition_variable>
#include <functional>

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
    void LoopForTP();

public:
    ThreadPool(int number_of_threads);
    ~ThreadPool();
    void AddTask(const std::function<void()> &task);
    bool PoolWorking();
    void EndPool();
};
#endif