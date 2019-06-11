#include <iostream>
#include <chrono>
#include <future>
#include <string>

int main(){
      
    std::cout<<std::endl;

    auto f1 = std::async( std::launch::async, []{
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< " first thread" << std::endl;
    });
   
    auto f2 = std::async( std::launch::async, []{
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<< " second thread" << std::endl;
    });
    
    std::cout << "call get methods " << std::endl;
    f1.get();
    f2.get(); 
    std::cout << "main thread " << std::endl;
    std::cout << std::endl;
    return 0;
}
