#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

struct CriticalData{
    std::mutex mtx;
};

void foo( CriticalData &a, CriticalData &b){
    a.mtx.lock();
    std::cout << "a: get first lock" << std::endl;
    std::this_thread::sleep_for( std::chrono::milliseconds(1));
    b.mtx.lock();
    std::cout << "b: get second lock" << std::endl;
    //process data (a,b)
    a.mtx.unlock();
    b.mtx.unlock();
}

int main(){
      
    std::cout<<std::endl;
    CriticalData cd1;
    CriticalData cd2;

    std::thread t1 { [&]{ foo(cd1, cd2);}};
    std::thread t2 { [&]{ foo(cd2, cd1);}};

    t1.join();
    t2.join();
    std::cout << std::endl;
    return 0;
}
