#include <iostream>
#include <thread>
#include <mutex>

std::once_flag onceFlag;

void foo(){
    std::call_once(onceFlag, []{std::cout<<"foo executed"<<std::endl;});
}

void bar(){
    std::call_once(onceFlag, []{std::cout<<"bar executed"<<std::endl;});
}

int main(){
      
    std::cout<<std::endl;
    
    std::thread t2 { bar };
    std::thread t1 { foo };
    
    std::thread t3 { bar };
    std::thread t4 { foo };

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << std::endl;
    return 0;
}
