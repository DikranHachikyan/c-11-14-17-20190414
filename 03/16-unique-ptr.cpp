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
    //c++11
    std::unique_ptr<Widget> w1 { new Widget(10,20)};
    w1->show();
    
    //c++14
    auto w2 = std::make_unique<Widget>(5, 6);
    w2->show();

    auto w3 = std::move(w2);
    w3->show();

    auto w4 = w1.release();
    std::cout<<"type of w4 is:"<<typeid(w4).name()<<std::endl;
    w4->show();
    delete w4;
    return 0;
}
