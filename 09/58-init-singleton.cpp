#include <iostream>
#include <thread>
#include <mutex>

class Singleton{
    private:
        static std::once_flag initInstanceFlag;
        static Singleton *singleton;

        Singleton()=default;
        ~Singleton()=default;
    public:
        Singleton(const Singleton &)=delete;
        Singleton &operator=(const Singleton &)=delete;

        static void initSingleton(){
            singleton = new Singleton();
        }

        static Singleton *getInstance(){
            // if (singleton == nullptr){
            //     singleton = new Singleton();
            // }
            std::call_once( initInstanceFlag, Singleton::initSingleton );
            return singleton;    
        }
};

Singleton *Singleton::singleton = nullptr;
std::once_flag Singleton::initInstanceFlag;

int main(){
      
    std::cout<<std::endl;
    
    std::cout<<"get instance 1:" << Singleton::getInstance()<<std::endl;
    std::cout<<"get instance 2:" << Singleton::getInstance()<<std::endl;

    std::cout << std::endl;
    return 0;
}
