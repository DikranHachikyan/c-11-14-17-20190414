#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <vector>

std::mutex mtx;
std::vector<int> rc_shared;

bool dataReady {false};
std::condition_variable condVar;

void waitForWork(){
    std::cout<<"waiting ..."<<std::endl;
    std::unique_lock<std::mutex> lck {mtx};
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    condVar.wait( lck, [](){ //push model
        return dataReady;
    });
    rc_shared[1] = 2;
    std::cout<<"work is done!"<<std::endl;

}

void waitForWork1(){
    std::cout<<"waiting ..."<<std::endl;
    std::unique_lock<std::mutex> lck {mtx};
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    condVar.wait( lck, [](){ //push model
        return dataReady;
    });
    rc_shared[2] = 33;
    std::cout<<"work is done!"<<std::endl;

}
void setDataReady(){
    rc_shared = {1, 0, 3};
    {
        std::lock_guard<std::mutex> guard {mtx};
        dataReady = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    std::cout<<"data prepared"<<std::endl;
    condVar.notify_all();
}

int main(){

    std::thread t1 {waitForWork};
    std::thread t2 {setDataReady};
    std::thread t3 {waitForWork1};

    t1.join();
    t2.join();
    t3.join();

    for( auto v : rc_shared){
        std::cout<<v<<"|";
    }
    std::cout<<std::endl;
    return 0;
}
