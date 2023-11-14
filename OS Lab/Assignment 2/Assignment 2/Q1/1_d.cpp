#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <cstdlib>
#include<time.h>
#include<mutex>
#include <thread>
#include<condition_variable>
using namespace std;

class Semaphore {
private:
    int count_;
    std::mutex mutex_;
    std::condition_variable condition_;
public:
    Semaphore(int count = 0) : count_(count) {}

    void Notify() {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        condition_.notify_one();
    }

    void Wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ == 0) {
            condition_.wait(lock);
        }
        --count_;
    }
};

// int count=0;

// int arr[]={0,0};
Semaphore s(1);

int turn=0;

void process1(string name,int n,int seed,int p_no){
    srand(seed);
    int i=0;
    while(i<n){
        // bool can_go=false;
        s.Wait();
        if(turn==p_no){
            // can_go=true;
            turn=(turn+1)%3;
            cout<<name<<" "<<"iteration no: "<<i+1<<endl;
            i++;
        }
        s.Notify();
        // if(can_go==false){
        //     continue;
        // }
        int t=rand()%1000000+(i%3)*10000;
        usleep(t);
        
        
    }
}



int main()
{
    // srand(time(0));
    thread threadX(process1,"PROCESS X",10,123,0);
    thread threadY(process1,"PROCESS Y",10,456,1);
    thread threadZ(process1,"PROCESS Z",10,789,2);
    threadX.join();
    threadY.join();
    threadZ.join();
  
    return 0;
}