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


int main(){
    auto w1 = std::make_shared<Widget>(10,20);
    std::weak_ptr<Widget> wk1(w1);
    std::shared_ptr<Widget> tmp;
    std::shared_ptr<Widget> tmp1;

    std::cout<<"weak ptr refs:"<<wk1.use_count()<<"\n"
             <<"shared ptr refs:"<<w1.use_count()
             <<std::endl;
    
    if( tmp = wk1.lock()){
        std::cout<<"tmp shared:"<<tmp<<"\n"
                 <<"tmp refs:"<<tmp.use_count()<<"\n"
                 <<"wk1 refs:"<<wk1.use_count()<<"\n"
                 <<"w1 refs:"<<w1.use_count()<<"\n"
                 <<"w1 shared:"<<w1
                 <<std::endl;
    }
    std::cout<<std::endl;
    if( tmp1 = wk1.lock()){
        std::cout<<"tmp1 shared:"<<tmp1<<"\n"
                 <<"tmp1 refs:"<<tmp1.use_count()<<"\n"
                 <<"wk1 refs:"<<wk1.use_count()<<"\n"
                 <<"w1 refs:"<<w1.use_count()<<"\n"
                 <<"w1 shared:"<<w1
                 <<std::endl;
    }

    std::cout<<"is expired:"<<std::boolalpha<<wk1.expired()<<std::endl;

    if( ! wk1.expired()){
        wk1.reset();
    }
    std::cout<<"is expired:"<<std::boolalpha<<wk1.expired()<<std::endl;
    return 0;
}
