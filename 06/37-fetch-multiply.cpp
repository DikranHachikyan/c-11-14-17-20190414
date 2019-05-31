#include <iostream>
#include <thread>
#include <atomic>

template <typename T>
T fetch_multiply( std::atomic<T> &shared, T mult ){
    T oldValue = shared.load();

    while( !shared.compare_exchange_strong(oldValue, oldValue * mult));

    return oldValue;
}


int main(){
    std::atomic<int> value {5};
    std::cout << "value=" << value << std::endl;
    fetch_multiply(value, 10);
    std::cout << "value=" << value << std::endl;
    std::cout<<std::endl;
    return 0;
}
