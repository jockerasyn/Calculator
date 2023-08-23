#include <vector>
#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <array>
#include <mutex>
#include <future>

// global mutex
std::mutex myMutex;

class MyFunctor
{
public:
    MyFunctor() {}
    MyDigit operator()(MyDigit &num) { return num * 2; }
};

auto myLambda = [](MyDigit &num)
{
    return num + 1;
};

class sum_of_arr_thread
{
public:
    void operator()(std::array<int, 10> arr, int arrbegin, int arrend, int &sum)
    {
        std::lock_guard<std::mutex> guard(myMutex);
        for (int i = arrbegin; i < arrend; i++)
        {
            sum += arr[i];
        }
        std::cout << "value after every thread: " << sum << std::endl;
    }
};

class sum_of_arr_async
{
public:
    int operator()(std::array<int, 10> arr, int arrbegin, int arrend)
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

int main()
{

    // functor test
    MyDigit a = 3.5;
    MyFunctor doubler;
    MyDigit b = doubler(a);
    std::cout << b << a;

    // lambda test
    MyDigit c = myLambda(a);
    std::cout << c;

    // array operations - for next task
    std::array<int, 10> array;
    for (int i = 0; i < array.size(); i++)
        array[i] = i + 1;

    // thread with
    int sum = 0;
    std::thread t1(sum_of_arr_thread(), array, 0, int(round(array.size() / 2) + 1), std::ref(sum));
    std::thread t2(sum_of_arr_thread(), array, int(round(array.size() / 2) + 1), int(array.size()), std::ref(sum));
    t1.join();
    t2.join();
    std::cout << "sum of array elements = " << sum << std::endl;
    auto f1 = std::async(sum_of_arr_async(), array, 0, int(round(array.size() / 2) + 1));
    auto f2 = std::async(sum_of_arr_async(), array, int(round(array.size() / 2) + 1), int(array.size()));
    int sum1 = f1.get();
    int sum2 = f2.get();
    std::cout << "result of sum = " << sum1 + sum2 << std::endl;
}