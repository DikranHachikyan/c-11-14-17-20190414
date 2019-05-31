#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <vector>

std::vector<int> sharedResource;
std::atomic<bool> dataProduced {false};

void producer(){
    sharedResource = {1,2,3,4};
    dataProduced.store(true, std::memory_order_release);
}



void consumer(){
    while(!dataProduced.load(std::memory_order_acquire));
    sharedResource[1] = 22;
}

int main(){
    std::thread t3 {consumer};
    std::thread t2 {producer};
    std::thread t1 {consumer};


    t1.join();
    t2.join();
    t3.join();


    for( auto v : sharedResource){
        std::cout << v << "|";
    }
    
    std::cout<<std::endl;
    return 0;
}
