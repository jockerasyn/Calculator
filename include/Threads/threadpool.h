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
#include <vector>

class ThreadPool
{
private:
    std::vector<std::thread> pool_of_threads;
    std::queue<std::packaged_task<int()>> task_queue;
    std::mutex pool_mutex;
    std::mutex condition_mutex;
    std::condition_variable pool_condition;
    bool finish_searching_for_task;
    void LoopForTP();

public:
    ThreadPool(int number_of_threads);
    ~ThreadPool();
    void AddTask(std::packaged_task<int()> task);

    bool PoolWorking();
    void EndPool();
};

#endif
