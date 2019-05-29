#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class SpinLock{
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

    public:
        void lock(){
            while( flag.test_and_set());
        }

        void unlock(){
            flag.clear();
        }
};

SpinLock spin;
int data[] = {1, 2, 3, 4, 5};

void increment();
void power();
void show();

int main(){
    std::thread t1 {power};
    std::thread t2 {increment};

    t1.join();
    t2.join();
    return 0;
}

void increment(){
    int i = 0;
    spin.lock();
    std::cout<<"begin critical section"<<std::endl;
    while( i < 5 ){
        if( data[i] % 2 == 0 ){
            ++data[i];
        }
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    show();
    std::cout<<"end critical section"<<std::endl;
    spin.unlock();
}

void power(){
    int i = 0;
    spin.lock();
    std::cout<<"begin critical section"<<std::endl;
    while( i < 5 ){
        if( data[i] % 2 == 0 ){
            data[i] *= data[i] ;
        }
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    show();
    std::cout<<"end critical section"<<std::endl;
    spin.unlock();
}
void show(){
    for( int i=0; i < 5; i++){
        std::cout<<data[i]<<"|";
    }
    std::cout<<std::endl;
}