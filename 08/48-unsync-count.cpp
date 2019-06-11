#include <iostream>
#include <thread>
#include <chrono>
#include <string>

class Worker{
    private:
        std::string _name;
    public:
        Worker( std::string name): _name {name}{}

        void operator()(){
            for( int i = 1 ; i <= 3; i++){
                //begin
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                //end
                std::cout << _name << " : work "
                          << i     << " done!"
                          <<std::endl;
            }
        }
};

int main(){
      
    std::cout<<std::endl;
    std::cout <<"begin\n\n";

    std::thread t1 { Worker { "thread 1"} };
    std::thread t2 { Worker { " thread 2"} };
    std::thread t3 { Worker { "  thread 3"} };
    std::thread t4 { Worker { "   thread 4"} };
    std::thread t5 { Worker { "    thread 5"} };
    std::thread t6 { Worker { "     thread 6"} };
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
    std::cout << "\n end" << std::endl;

    std::cout << std::endl;
    return 0;
}
