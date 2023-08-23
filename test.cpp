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
    std::promise<int> sum1_promise;
    std::promise<int> sum2_promise;
    std::future<int> sum1_return = sum1_promise.get_future();
    std::future<int> sum2_return = sum2_promise.get_future();
    std::thread t1(sum_of_arr_thread(), std::ref(array), 0, int(round(array.size() / 2) + 1), std::move(sum1_promise));
    std::thread t2(sum_of_arr_thread(), std::ref(array), int(round(array.size() / 2) + 1), int(array.size()), std::move(sum2_promise));
    t1.join();
    t2.join();
    std::cout << "sum of array elements = " << sum1_return.get() + sum2_return.get() << std::endl;

    // threads with reading files
    std::thread t3(filereader(), "txt_files/text1.txt");
    std::thread t4(filereader(), "txt_files/text2.txt");
    std::thread t5(filereader(), "txt_files/text3.txt");
    t3.join();
    t4.join();
    t5.join();
}
