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

class sum_of_arr_thread
{
public:
    void operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::promise<int> sum_promise);
};

class sum_of_arr_atomic
{
public:
    void operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::atomic_int &sum, std::atomic_int &th_info);
};

class filereader
{
public:
    void operator()(const char *path, std::mutex &readMutex);
};
#endif