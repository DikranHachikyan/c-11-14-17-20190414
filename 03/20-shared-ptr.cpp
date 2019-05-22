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
    auto w1 = std::make_shared<Widget>(10,20);

    std::cout<<"begin of main; refs:"<<w1.use_count()<<std::endl;
    {
        auto w2 = w1;
        {
            auto w3 = w2;
            std::cout<<"inner block; refs:"<<w1.use_count()<<std::endl;
        }
        std::cout<<"outer block; ref:"<<w1.use_count()<<std::endl;
    }
    std::cout<<"end of main; refs:"<<w1.use_count()<<std::endl;
    return 0;
}
