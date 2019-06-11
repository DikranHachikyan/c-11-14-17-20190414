#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex mtx;

thread_local std::string s1 { "hello from " };

void addThreadLocalData( std::string const &s2){
    s1 += s2;
    std::lock_guard<std::mutex> guard { mtx };
    std::cout<<s1<<std::endl; 
    std::cout<<"&s1:"<<&s1<<std::endl;
    std::cout<<std::endl;
}

int main(){
      
    std::cout<<std::endl;

    std::thread t1 { addThreadLocalData, "t1"};
    std::thread t2 { addThreadLocalData, "t2"};
    std::thread t3 { addThreadLocalData, "t3"};
    std::thread t4 { addThreadLocalData, "t4"};

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout<<"main s1:"<<s1<<std::endl;
    std::cout<<"main addr s1:"<<&s1<<std::endl;
    std::cout << std::endl;
    return 0;
}
