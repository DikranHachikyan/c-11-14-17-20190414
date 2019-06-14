#include <thread>

class A{
    public:
        void foo(int &a){
            
        }

        void bar(){
            int x=2;
            auto f = [*this](int &z){ foo(z);};
            std::thread t1 {foo, x};
        }
};
