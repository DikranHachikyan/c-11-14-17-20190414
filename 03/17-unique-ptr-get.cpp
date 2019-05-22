#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>

class Widget{
    private:
        int _x;
        int _y;
    public:

        Widget(int x, int y):_x {x}, _y {y}{
            std::cout<<"Ctor Widget"<<std::endl;
        }

        Widget():Widget(0,0){};

        ~Widget(){
            std::cout<<"Dtor Widget"<<std::endl;
        }

        //Copy Ctor
        Widget(const Widget &wdg):_x{ wdg._x}, _y{wdg._y}{
            std::cout<<"Copy Ctor"<<std::endl;
        }
        //Copy Assignment
        Widget &operator=(const Widget &wdg){
            _x = wdg._x;
            _y = wdg._y;
            std::cout<<"copy assignment"<<std::endl;
            return *this;
        }

        //Move Ctor
        Widget( Widget &&wdg): 
                _x{ std::exchange(wdg._x, 0)},
                _y{ std::exchange(wdg._y, 0)}{
            std::cout<<"Move Ctor"<<std::endl;        
        }
        //Move Assign
        Widget &operator=( Widget &&wdg ){
            if( this != &wdg ){
                _x = std::exchange(wdg._x,0);
                _y = std::exchange(wdg._y,0);
            }
            std::cout<<"move assignment"<<std::endl;
            return *this;
        }

        void show(){
            std::cout<<"("<<_x<<","<<_y<<")"<<std::endl;
        }
        
};


int main(){
    auto w1 = std::make_unique<Widget>(10,20);
    auto w2 = w1.get();
    //std::cout<<"type of w2 is:"<<typeid(w2).name()<<std::endl;
    //w2->show();
    //!! 
    //delete w2;
    //w1->show();
    decltype(w2) w3 = w1.release();
    w3->show();
    if( w1 == nullptr){
        std::cout<<"w1 not managed by unique ptr"<<std::endl;
    }
    delete w3;
    //replace

    auto w4 = std::make_unique<Widget>(5,6);
    w4->show();

    w4.reset( std::make_unique<Widget>(1,2).release());
    w4->show();
    return 0;
}
