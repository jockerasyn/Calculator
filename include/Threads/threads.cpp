#include "threads.h"

void sum_of_arr_thread::operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::promise<int> sum_promise)
{
    int sum = 0;
    for (int i = arrbegin; i < arrend; i++)
        sum += arr[i];
    sum_promise.set_value(sum);
}

void sum_of_arr_atomic::operator()(std::array<int, 10> &arr, int arrbegin, int arrend, std::atomic_int &sum, std::atomic_int &th_info)
{
    for (int i = arrbegin; i < arrend; i++)
        sum += arr[i];
    th_info += 1;
}

void filereader::operator()(const char *path, std::mutex &readMutex)
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