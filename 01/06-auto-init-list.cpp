#include <iostream>
#include <cstdlib>
#include <typeinfo>



int main(){
    auto s1 {1};

    auto s2 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    std::cout<<"type of s1 is:"<<typeid(s1).name()<<std::endl;
    
    std::cout<<"type of s2 is:"<<typeid(s2).name()<<std::endl;
    
    for( auto i: s2){
        std::cout<<i<<std::endl;
    }
    return 0;
}
