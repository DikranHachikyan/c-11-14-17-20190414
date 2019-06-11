#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

struct CriticalData{
    std::mutex mtx;
};

void foo( CriticalData &a, CriticalData &b){
    //std::defer_lock
    //std::adopt_lock
    std::unique_lock<std::mutex> guard_a {a.mtx, std::defer_lock};

    std::cout << " a: get first lock " << std::this_thread::get_id()<< std::endl;

    std::this_thread::sleep_for( std::chrono::milliseconds(1));
    
    std::unique_lock<std::mutex> guard_b {b.mtx, std::defer_lock};
    //до тук unique_lock просто държи mutex-ите
    std::cout << " b: get second lock "<< std::this_thread::get_id() << std::endl;
    //заключва атомарно
    std::lock(guard_a,guard_b);
    //process data (a,b)
    std::cout << "end of a,b processing" << std::endl;

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
