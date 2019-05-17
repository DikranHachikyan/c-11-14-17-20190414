#include <iostream>
#include <typeinfo>
#include <string>

int main(){

    //auto show = [](){ std::cout<<"lambda expression"<<std::endl; };
    //auto show = []{ std::cout<<"lambda expression"<<std::endl; };
    auto show = []()->void{ std::cout<<"lambda expression"<<std::endl; };

    show();

    //Params
    auto showParams = [](const std::string &message){
        std::cout<<message<<std::endl;
    };

    showParams("lambda with params");

    //Capture
    int n = 1;
    std::string s1 = "Hello Lambda";

    auto showCap = [s1,n](){
        std::cout<<"captured by value: s1="<<s1<<", n="<<n<<std::endl;
        //assignment of read-only variable ‘n’
        //n = 10;
    };

    showCap();

    //Mutable 
    auto showMutable = [&](){
        n = 100;
        s1 = "Mutable Lambda";
    };

    showMutable();
    std::cout<<"s1="<<s1<<" n="<<n<<std::endl;

    auto showMutable2 = [=,&s1](){
        std::cout<<"n="<<n<<std::endl;
        //n=2; error
        s1 = "mutable lambda";
    };
    
    showMutable2();
    std::cout<<"s1:"<<s1<<std::endl;

    auto showMutable3 = [n]()mutable->int{
        return ++n;
    };

    std::cout<<"n="<<showMutable3()<<std::endl;
    return 0;
}
