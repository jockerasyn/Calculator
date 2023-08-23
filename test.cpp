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

class sum_of_arr
{
private:
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

    // array operations
    std::array<int, 10> array;
    for (int i = 0; i < array.size(); i++)
        array[i] = i + 1;

    int sum = 0;
    std::thread t1(sum_of_arr(), array, 0, int(round(array.size() / 2) + 1), std::ref(sum));
    std::thread t2(sum_of_arr(), array, int(round(array.size() / 2) + 1), int(array.size()), std::ref(sum));
    t1.join();
    t2.join();
    std::cout << "sum of array elements = " << sum << std::endl;
}