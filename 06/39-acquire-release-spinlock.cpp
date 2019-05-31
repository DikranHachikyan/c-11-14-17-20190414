#include <iostream>
#include <thread>
#include <atomic>
#include <string>

class SpinLock{
    private:
        std::atomic_flag flag;
    public:
        SpinLock():flag {ATOMIC_FLAG_INIT} {}

        void lock(){
            while( flag.test_and_set(std::memory_order_acq_rel));
        }

        void unlock(){
            flag.clear(std::memory_order_release);
        }
    
};

SpinLock spin;

void workOnSharedResource(){
    spin.lock();
    std::cout<<"work on shared resource"<<std::endl;
    std::this_thread::sleep_for( std::chrono::milliseconds(2000));
    std::cout<<"end of work"<<std::endl;
    spin.unlock();
}

int main(){
    std::thread t1 {workOnSharedResource};
    std::thread t2 {workOnSharedResource};

    t1.join();
    t2.join();

    std::cout<<std::endl;
    return 0;
}
