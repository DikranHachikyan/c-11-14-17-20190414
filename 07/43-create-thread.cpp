#include <iostream>
#include <thread>

void foo(){
    std::cout<< "foo:" << std::this_thread::get_id() << std::endl;
}

class Foo {
    public:
        void operator()(){
            std::cout << "Foo obj:" << std::this_thread::get_id() << std::endl;
        }
};

int main(){
    
    std::cout<<std::endl;
    std::thread t1 { foo };

    std::thread t2 { Foo {} };

    auto f = []{ std::cout<< "lambda:" << std::this_thread::get_id() << std::endl;};
    std::thread t3 { f };


    t1.join();
    t2.join();
    t3.join();
  
    std::cout<<std::endl;
    return 0;
}
