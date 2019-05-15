#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>

class Widget{
    public:
        std::string _label {"default label"};
        Widget(){ std::cout<<"Widget Ctor"<<std::endl;}

        //Copy Ctor
        Widget(const Widget &wdg){
            _label = wdg._label;
            std::cout<<"Copy Ctor Widget"<<std::endl;
        }
        //Copy Assignment
        Widget &operator=(const Widget &wdg){
            _label = wdg._label;
            std::cout<<"Copy Assignment"<<std::endl;
            return *this;
        }
};

const Widget w {};

const Widget &foo(){
    return w;
}

int main(){
    const Widget &w1 = foo();
    //w1._label = "Ok!";//Error!!!

    //remove ref, const !!!
    auto w2 = foo();
    w2._label = "Ok";

    std::cout<<"w2:"<<w2._label<<" w:"<<w._label<<std::endl;

    const auto &w3 = foo();
    //w3._label = "Ok"; //Error!!

    //keeps ref,const
    decltype( foo() ) w4 = foo();
    //w4._label = "Ok";
    std::cout<<"w4:"<<w4._label<<std::endl;

    decltype( w )  w5 = foo();
    //w5._label = "Ok";

    std::cout<<"type of w1:"<<typeid(w1).name()<<std::endl;
    std::cout<<"type of w2:"<<typeid(w2).name()<<std::endl;
    std::cout<<"type of w3:"<<typeid(w3).name()<<std::endl;
    std::cout<<"type of w4:"<<typeid(w4).name()<<std::endl;
    std::cout<<"type of w5:"<<typeid(w5).name()<<std::endl;
    return 0;
}
