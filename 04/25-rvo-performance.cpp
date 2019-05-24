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

std::vector<int> foo(){
    return std::vector<int>(1,1);
}

int main(){

    for( int i=0; i < 100000000; ++i){
        foo();
    }   
    return 0;
}
