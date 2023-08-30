#ifndef _THREADPOOL_F_H_
#define _THREADPOOL_F_H_

#include <thread>
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <functional>
#include <vector>
#include <atomic>
#include <future>

class ThreadPool_F
{
private:
    std::vector<std::thread> pool_of_threads;
    std::queue<std::function<int()>> task_queue;
    std::vector<int> results;
    std::mutex pool_mutex;
    std::mutex condition_mutex;
    std::condition_variable pool_condition;
    std::atomic<bool> finish_searching_for_task;
    std::mutex result_mutex;

    void LoopForTP();

public:
    ThreadPool_F(int number_of_threads);
    ~ThreadPool_F();
    void AddTask(std::function<int()> task);
    bool PoolWorking();
    void EndPool();
    const std::vector<int> &GetResults();
};

#endif
