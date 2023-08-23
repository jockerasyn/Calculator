#include <thread>
#include <future>
#include <array>
#include <iostream>
#include <mutex>
#include <fstream>
#include <string>
#include <sstream>

extern std::mutex readMutex;

class sum_of_arr_async
{
public:
    int operator()(std::array<int, 10> &arr, int arrbegin, int arrend)
    {
        int sum = 0;
        for (int i = arrbegin; i < arrend; i++)
        {
            sum += arr[i];
        }
        std::cout << "sum for task = " << sum << std::endl;
        return sum;
    }
};

class sum_of_arr_thread
{
public:
    void operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::promise<int> sum_promise)
    {
        int sum = 0;
        for (int i = arrbegin; i < arrend; i++)
        {
            sum += arr[i];
        }
        sum_promise.set_value(sum);
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