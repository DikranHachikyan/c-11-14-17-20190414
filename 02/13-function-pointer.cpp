#include <iostream>
#include <typeinfo>
#include <string>
#include <functional>

void show( int n, const std::string &msg){
    std::cout<<"n="<<n<<" msg="<<msg<<std::endl;
}

int main(){
    void (*fp)(int,const std::string &);

    fp = show;

    fp(10, "function pointer");

    std::function<void(int,const std::string &)> fp1 = show;

    fp1(12, "std::function pointer");

    auto fp2 = show;

    fp2(14, "auto function pointer");
    std::cout<<"type of fp2 is:"<<typeid(fp2).name()<<std::endl;
    std::cout<<"type of fp1 is:"<<typeid(fp1).name()<<std::endl;

    return 0;
}
