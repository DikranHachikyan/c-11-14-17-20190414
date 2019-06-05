#include <iostream>
#include <thread>
#include <atomic>
#include <string>

std::atomic<std::string *> ptr;
int data;
std::atomic<int> atomicInt;

void producer(){
    //Store
    std::string *p = new std::string("c++ thread");
    data = 5;
    atomicInt.store(1024, std::memory_order_relaxed);
    std::atomic_thread_fence( std::memory_order_release);
    //Store
    ptr.store( p , std::memory_order_release);
}

void consumer(){
    //Load
    std::string *p;
    while( !(p = ptr.load( std::memory_order_relaxed)));
    std::atomic_thread_fence( std::memory_order_acquire);
    //Load
    std::cout << " *p: "  << *p << std::endl;
    std::cout << " data:" << data << std::endl;
    std::cout << " atomic int:" << atomicInt.load(std::memory_order_relaxed) << std::endl; 
} 


int main(){
    
    std::cout<<std::endl;
    
    std::thread t1 {consumer};
    std::thread t2 {producer};

    t1.join();
    t2.join();

    delete ptr;
    std::cout<<std::endl;
    return 0;
}
