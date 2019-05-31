#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

using namespace std::chrono_literals;

std::vector<int> rc_shared;
std::atomic<bool> dataReady {false};

void waitForWork(){
    std::cout << "waiting ..." << std::endl;
    while( !dataReady.load() ){ //pull model
        std::this_thread::sleep_for(1000ms);
    }
    rc_shared[1] = 2;
    std::cout << "work is done" << std::endl;
}

void setDataReady(){
    rc_shared = {1, 0, 3};
    dataReady = true;
    std::cout << "data prepared" << std::endl;    
}

int main(){

    std::thread t1 {waitForWork};
    std::thread t2 {setDataReady};

    t1.join();
    t2.join();

    for( auto v : rc_shared){
        std::cout<<v<<"|";
    }
    std::cout<<std::endl;
    return 0;
}
