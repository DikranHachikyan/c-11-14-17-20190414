#include <iostream>
#include <cstdlib>
#include <typeinfo>

class Widget{

};

auto foo(){
    return 1; 
}

int main(){
    auto x {10.0};

    auto w { new Widget };

    std::cout<<"type of x is:"<<typeid(x).name()<<std::endl;
    std::cout<<"size of x is:"<<sizeof(x)<<std::endl;
    std::cout<<"type of w is:"<<typeid(w).name()<<std::endl;
    

    return 0;
}
