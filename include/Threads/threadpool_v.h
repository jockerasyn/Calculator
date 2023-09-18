#ifndef _THREADPOOL_V_H_
#define _THREADPOOL_V_H_

#include <thread>
#include <future>
#include <mutex>
#include <queue>
#include <cassert>
#include <condition_variable>
#include <functional>
#include <vector>
#include <atomic>

class ThreadPoolV
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
    ThreadPoolV(int number_of_threads);
    ~ThreadPoolV();
    void AddTask(std::packaged_task<int()> task);
    bool PoolWorking();
    void EndPool();
};

#endif
