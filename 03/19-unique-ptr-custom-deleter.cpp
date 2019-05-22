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

// void foo( Widget &&w){
//
// }
int main(){
    auto deleter = [](Widget *w){
        std::cout<<"custom deleter"<<std::endl;
        delete w;
    };

    std::unique_ptr<Widget,decltype(deleter)> w1( new Widget(1,2), deleter);

    w1->show(); 

    //foo( Widget());
    return 0;
}
