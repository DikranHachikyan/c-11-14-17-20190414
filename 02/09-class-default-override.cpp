#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
class GenericWidget{
    public:
        virtual ~GenericWidget()=default;
        virtual void moveTo(int,int)=0;
};

class Widget: public GenericWidget{
    private:
        std::string _label {"default label"};
    public:
        Widget()=default;
        ~Widget(){
            std::cout<<"Dtor Widget"<<std::endl;
        }

        Widget(const std::string &label):_label{label}{
            std::cout<<"Ctor Widget"<<std::endl;
        }

        //Copy Ctor
        Widget(const Widget &)=delete;
        //Copy Assignment
        Widget &operator=(const Widget &)=delete;

        void show(){
            std::cout<<"Label:"<<_label<<std::endl;
        }
        //Override
        virtual void moveTo(int x, int y) override {
            std::cout<<"move to:("<<x<<","<<y<<")"<<std::endl;
        }
};

int main(){
    GenericWidget *gw { new Widget("Ok")};

    gw->moveTo(10,20);
    delete gw;
    return 0;
}
