#include <iostream>
#include <thread>


int main(){
    
    std::cout<<std::endl;
  
    auto f = []{ std::cout<< "lambda:" << std::this_thread::get_id() << std::endl;};
    std::thread t3 { f };

    //t3.join();
    t3.detach();
    if ( t3.joinable() ){
        t3.join();
    }
    int i;
    std::cin>>i;
    std::cout<<std::endl;
    return 0;
}
