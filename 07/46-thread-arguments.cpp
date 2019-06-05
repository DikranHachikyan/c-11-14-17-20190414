#include <iostream>
#include <thread>
#include <utility>
#include <chrono>

class Sleeper {
    private:
        int & _i;
    public:
        Sleeper( int &i): _i {i}{}

        void operator()(int k){
            for( int j = 0 ; j < 5 ; ++j){
                std::this_thread::sleep_for(std::chrono::microseconds(100));
                _i +=k;
            }
            std::cout << std::this_thread::get_id() << std::endl;
        }
};

int main(){
    
    std::cout<<std::endl;
    int value = 1000;

    std::thread t1(Sleeper(value), 5);
    t1.join();
    std::cout<< "value:" << value << std::endl; 
    std::cout<<std::endl;
    return 0;
}
