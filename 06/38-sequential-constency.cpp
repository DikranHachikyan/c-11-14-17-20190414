#include <iostream>
#include <thread>
#include <atomic>
#include <string>

std::string work;
std::atomic<bool> ready {false};

void consumer(){
    while( !ready.load(std::memory_order_seq_cst));
    std::cout << work << std::endl;
}

void producer(){
    work = "done";
    ready.store(true, std::memory_order_seq_cst);
}

int main(){
    std::thread t1 {consumer};
    std::thread t2 {producer};

    t1.join();
    t2.join();

    std::cout<<std::endl;
    return 0;
}
