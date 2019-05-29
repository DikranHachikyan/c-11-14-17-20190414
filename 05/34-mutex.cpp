#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;
int data[] = {1, 2, 3, 4, 5};

void increment();
void power();
void show();

int main(){
    std::thread t2 {increment};
    std::thread t1 {power};

    t1.join();
    t2.join();
    return 0;
}

void increment(){
    int i = 0;
    mtx.lock();
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
    mtx.unlock();
}

void power(){
    int i = 0;
    mtx.lock();
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
    mtx.unlock();
}
void show(){
    for( int i=0; i < 5; i++){
        std::cout<<data[i]<<"|";
    }
    std::cout<<std::endl;
}