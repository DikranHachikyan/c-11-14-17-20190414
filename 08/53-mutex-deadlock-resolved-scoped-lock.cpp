#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

struct CriticalData{
    std::mutex mtx;
};

void foo( CriticalData &a, CriticalData &b){
    
    std::cout << " a: get first lock " << std::this_thread::get_id()<< std::endl;

    std::this_thread::sleep_for( std::chrono::milliseconds(1));

    std::cout << " b: get second lock "<< std::this_thread::get_id() << std::endl;
    std::scoped_lock<std::mutex,std::mutex> lk { a.mtx, b.mtx};
    //заключва атомарно
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
