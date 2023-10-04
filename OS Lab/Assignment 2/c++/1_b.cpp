#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <time.h>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class Semaphore
{
private:
    int count_;
    std::mutex mutex_;
    std::condition_variable condition_;

public:
    Semaphore(int count = 0) : count_(count) {}

    void Notify()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        condition_.notify_one();
    }

    void Wait()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ == 0)
        {
            condition_.wait(lock);
        }
        --count_;
    }
};

// int count=0;

int arr[] = {0, 0};
Semaphore s(1);

void process1(string name, int n, int seed)
{
    srand(seed);
    while (arr[0] < n)
    {
        // bool can_go = false;
        s.Wait();
        if (arr[1] >= arr[0])
        {
            // can_go = true;
            int i = arr[0];

            cout << name << " "
                 << "iteration no: " << i + 1 << endl;
            arr[0]++;
        }
        s.Notify();
        // if (can_go == false)
        // {
        //     continue;
        // }
        int t = rand() % 1000000 + (arr[0] % 3) * 10000;
        usleep(t);
    }
}

void process2(string name, int n, int seed)
{
    srand(seed);
    while (arr[1] < n)
    {
        // bool can_go=false;
        // s.Wait();
        // if(arr[1]>=arr[0]){
        //     can_go=true;
        // }
        // s.Notify();
        // if(can_go==false){
        //     continue;
        // }
        int i = arr[1];
        int t = rand() % 1000000 + (i % 3) * 10000;
        usleep(t);

        cout << name << " "
             << "iteration no: " << i + 1 << endl;
        s.Wait();
        arr[1]++;
        s.Notify();
    }
}

int main()
{
    // srand(time(0));
    thread threadX(process1, "PROCESS X", 10, 123);
    thread threadY(process2, "PROCESS Y", 10, 456);
    threadX.join();
    threadY.join();

    return 0;
}