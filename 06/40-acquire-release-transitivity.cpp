#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <vector>

std::vector<int> sharedResource;
std::atomic<bool> dataProduced {false};
std::atomic<bool> dataConsumed {false};

void producer(){
    sharedResource = {1,2,3,4};
    dataProduced.store(true, std::memory_order_release);
}

void delivery(){
    while( !dataProduced.load(std::memory_order_acquire));
    dataConsumed.store(true,std::memory_order_release);
}

void consumer(){
    while(!dataConsumed.load(std::memory_order_acquire));
    sharedResource[1] = 22;
}

int main(){
    std::thread t1 {consumer};
    std::thread t2 {producer};
    std::thread t3 {delivery};

    t1.join();
    t2.join();
    t3.join();

    for( auto v : sharedResource){
        std::cout << v << "|";
    }
    
    std::cout<<std::endl;
    return 0;
}
