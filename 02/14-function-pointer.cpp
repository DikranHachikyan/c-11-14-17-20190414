#include <iostream>
#include <typeinfo>
#include <string>
#include <functional>

int main(){
    int (*fp)(int);
    int k = 5;

    fp = [](int v)->int{ return v * v;};

    std::cout<<fp(10)<<std::endl;

    //cannot convert ‘main()::<lambda(int)>’ to ‘int
    //(*)(int)’ in assignment
    //fp = [k](int v)->int{ return v * k;};

    std::function<int(int)> fp1 = [k](int v)->int{ return v * k;};

    std::cout<<fp1(3)<<std::endl;
    return 0;
}
