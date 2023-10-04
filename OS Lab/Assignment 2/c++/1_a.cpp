#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <cstdlib>
#include<time.h>
#include<mutex>
using namespace std;

int count=0;

void process(string name,int n,int seed,int &count){
    srand(seed);
    for(int i=0;i<n;i++){
        int t=rand()%1000000+(i%3)*10000;
        usleep(t);
        
        cout<<name<<" "<<getpid()<<" "<<"iteration no: "<<i+1<<endl;
    }
}


  
int main()
{
    // srand(time(0));
    pid_t X = fork();
    int count=0;
  
    if(X==0){
        //inside first(X) process
        process("PROCESS X",10,123,count);
    }
    else{
        // sleep(2);
        pid_t Y=fork();
        if(Y==0){
            //inside second process(Y)
            process("PROCESS Y",10,456,count);
        }
        else{
            wait(nullptr);
            wait(nullptr);
            cout<<"End of main parent program"<<endl;
        }
    }
  
    return 0;
}