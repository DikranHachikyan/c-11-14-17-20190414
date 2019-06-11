#include <iostream>
#include <thread>
#include <future>
#include <string>

int main(){
      
    std::cout<<std::endl;
    int res;
    std::thread t1 {[&]{ res = 120 + 50;}};
    t1.join();
    std::cout << "t1 res=" << res << std::endl;

    auto fut = std::async([]{ return 120 + 50;});
    std::cout << "fut.get() = " << fut.get() << std::endl;
   
    std::cout << std::endl;
    return 0;
}
