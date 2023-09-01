#include <condition_variable>
#include <iostream>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady{false};

void waitingForWork()
{
    std::cout << "Waiting " << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, []
                 { return dataReady; }); // (4)
    dataReady = false;
    std::cout << "Running " << std::endl;
}

void setDataReady()
{
    {
        std::lock_guard<std::mutex> lck(mutex_);
        dataReady = true;
        std::cout << "Data prepared" << std::endl;
    }
    condVar.notify_all(); // (3)
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

// int main()
// {

//     std::cout << std::endl;

//     std::thread t11(waitingForWork); // (1)
//     std::thread t12(waitingForWork);
//     std::thread t13(waitingForWork);
//     std::thread t14(waitingForWork);
//     std::thread t21(setDataReady); // (2)
//     std::thread t22(setDataReady);
//     std::thread t23(setDataReady);
//     std::thread t24(setDataReady);

//     t11.join();
//     t12.join();
//     t13.join();
//     t14.join();
//     t21.join();
//     t22.join();
//     t23.join();
//     t24.join();
//     std::cout << std::endl;
// }