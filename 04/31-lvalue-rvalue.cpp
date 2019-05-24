#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>
#include <vector>

class Widget{
    private:
        int _x;
        int _y;
    public:

        Widget(int x, int y):_x {x}, _y {y}{
            std::cout<<"Ctor Widget ("<<_x<<","<<_y<<")"<<std::endl;
        }

        Widget():Widget(0,0){};

        ~Widget(){
            std::cout<<"Dtor Widget ("<<_x<<","<<_y<<")"<<std::endl;
        }

        //Copy Ctor
        Widget(const Widget &wdg):_x{ wdg._x}, _y{wdg._y}{
            std::cout<<"Copy Ctor ("<<_x<<","<<_y<<")"<<std::endl;
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
            std::cout<<"Move Ctor ("<<_x<<","<<_y<<")"<<std::endl;        
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
void foo( Widget &wdg){
    std::cout<<"lvalue"<<std::endl;
}

void foo( Widget &&rhs){
    std::cout<<"rvalue"<<std::endl;
}

Widget get(){
    return Widget(6,6);
}

void print( Widget &&rhs){
    //Widget w = rhs; //copy ctor
    Widget w = std::move(rhs); //move ctor
    rhs.show();
}

int main(){
    Widget w;

    std::cout<<"---------- 1 ------------"<<std::endl;
    foo(w);
    std::cout<<"---------- 2 ------------"<<std::endl;
    foo(get());
    std::cout<<"---------- 3 ------------"<<std::endl;
    foo(std::move(w));
    std::cout<<"---------- 4 ------------"<<std::endl;
    Widget w1 {1,2}, w2 {3,4};
    std::swap(w1,w2);
    w1.show();
    std::cout<<"---------- 5 ------------"<<std::endl;
    auto w3 = std::move(w1);
    w1.show();
    std::cout<<"---------- 6 ------------"<<std::endl;
    print(get());
    std::cout<<"---------- end ------------"<<std::endl;
    return 0;
}
