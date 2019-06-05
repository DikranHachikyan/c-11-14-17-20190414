#include <iostream>
#include <thread>
#include <utility>
#include <chrono>

int main(){
    
    std::cout<<std::endl;
    std::cout << " hardware concurrency:" << std::thread::hardware_concurrency()
              <<std::endl;
    auto f1 = []{std::cout << "f1:" << std::this_thread::get_id() << std::endl;};
    auto f2 = []{std::cout << "f2:" << std::this_thread::get_id() << std::endl;};

    std::thread t1 { f1 };
    std::thread t2 { f2 };

    std::cout<<std::endl;
    std::swap(t1,t2);

    std::cout<<std::endl;
    std::cout<<"after swap:\nt1"<<t1.get_id()<<std::endl;
    std::cout<<"t2:"<<t2.get_id()<<std::endl;
    t1.join();
    t2.join();
    std::cout<<std::endl;
    return 0;
}
