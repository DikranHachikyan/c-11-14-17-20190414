#include <iostream>
#include <cstdlib>

class Widget{
    private:
        int _x {0};
        int _y = 0;   //Ok!!
        //int _z(0); //Error 
    public:
        Widget(int x, int y): _x {x}, _y {y}{
            std::cout<<"Ctor Widget ("<<_x<<", "<<_y<<")"<<std::endl;
        }

        Widget():Widget(0,0){

        }

        void show(){
            std::cout<<"show: ("<<_x<<","<<_y<<")"<<std::endl;
        }
};

int main(){
    Widget w1(1,2);
    //Error
    //Widget w2();
    Widget w3 {};
    Widget w4 {7,9};

    w1.show();
    //w2.show();
    w3.show();
    w4.show();
    return 0;
}
