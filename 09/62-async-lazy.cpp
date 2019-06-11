#include <iostream>
#include <chrono>
#include <future>
#include <string>

int main(){
      
    std::cout<<std::endl;
    auto begin = std::chrono::system_clock::now();

    auto asyncLazy = std::async(std::launch::deferred, 
                                []{ return std::chrono::system_clock::now();});
    auto asyncSimp = std::async(std::launch::async,
                                []{return std::chrono::system_clock::now();});
    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto lazyStart = asyncLazy.get() - begin;
    auto simpStart = asyncSimp.get() - begin;

    auto lazyDuration = std::chrono::duration<double>(lazyStart).count();
    auto simpDuration = std::chrono::duration<double>(simpStart).count();

    std::cout << "async lazy eval. after:" << lazyDuration 
              << " seconds"<<std::endl;
   
    std::cout << "async simple eval. after:" << simpDuration 
              << " seconds"<<std::endl;
   
    std::cout << std::endl;
    return 0;
}
