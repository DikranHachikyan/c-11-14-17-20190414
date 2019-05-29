#include <iostream>
#include <thread>
#include <chrono>

void hello_thread(){
    std::this_thread::sleep_for( std::chrono::milliseconds(2000));
    std::cout<<"Hello Thread!"<<std::endl;
}

int main(){
    
    std::thread t {hello_thread};

    t.join();
    return 0;
}
