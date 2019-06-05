#include <iostream>
#include <thread>
#include <utility>
#include <chrono>

class ScopedThread {
    private:
        std::thread _t;
    public:
        explicit ScopedThread(std::thread t): _t { std::move(t)} {
            if( ! _t.joinable() ) throw std::logic_error("No thread");
        };

        ~ScopedThread(){
            _t.join();
        }

        ScopedThread(const ScopedThread &)=delete;
        ScopedThread &operator=(const ScopedThread &)=delete;
};

int main(){
    
    std::cout<<std::endl;
    auto f = []{ 
            std::cout << "Thread:" << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            };
    ScopedThread st { std::thread {f} };
    
    std::cout<<std::endl;
    return 0;
}
