#include <thread>
#include <future>
#include <array>
#include <iostream>

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