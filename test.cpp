#include <vector>
#include "Animal/animalfarm.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/writer.h"
#include "Animal/parsingError.h"
#include "Digit/digit.h"
#include <iostream>
#include <functional>
#include <array>
#include <mutex>
#include "Threads/threads.h"

// global mutex
std::mutex myMutex;
std::mutex readMutex;

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

    // threads with mutex
    int sum = 0;
    std::thread t1(sum_of_arr_thread(), std::ref(array), 0, int(round(array.size() / 2) + 1), std::ref(sum));
    std::thread t2(sum_of_arr_thread(), std::ref(array), int(round(array.size() / 2) + 1), int(array.size()), std::ref(sum));
    t1.join();
    t2.join();
    std::cout << "sum of array elements = " << sum << std::endl;

    // threads without mutex
    auto f1 = std::async(sum_of_arr_async(), std::ref(array), 0, int(round(array.size() / 2) + 1));
    auto f2 = std::async(sum_of_arr_async(), std::ref(array), int(round(array.size() / 2) + 1), int(array.size()));
    int sum1 = f1.get();
    int sum2 = f2.get();
    std::cout << "result of sum = " << sum1 + sum2 << std::endl;

    // threads with reading files
    std::thread t3(filereader(), "txt_files/text1.txt");
    std::thread t4(filereader(), "txt_files/text2.txt");
    std::thread t5(filereader(), "txt_files/text3.txt");
    t3.join();
    t4.join();
    t5.join();
}