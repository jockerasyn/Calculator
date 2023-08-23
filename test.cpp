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

class increment
{
public:
    increment() {}
    int operator()(int arr_num) const
    {
        return arr_num + 1;
    }
};

class sum
{
public:
    // template <std::size_t SIZE>
    // void operator()(std::array<int, SIZE> &arr, int arrbegin, int arrend)
    // {
    //     int sum = 0;
    //     for (int i = arrbegin; i < arrend; i++)
    //     {
    //         sum += arr[i];
    //     }
    //     std::cout << sum << " ";
    // }
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

    std::thread t1(sum(), array, 0, round(array.size() / 2) + 1);
    // int sum2 = sum_of_arr(array, round(array.size() / 2) + 1, array.size());
    // std::cout << sum1 << " " << sum2;
}