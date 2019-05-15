#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>

class Widget{
    private:
        std::string _label {"default label"};
    public:
        Widget()=default;
        ~Widget()=default;

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
};

int main(){
    Widget w1("Ok!");
    Widget w2 {"Cancel"};
    Widget w3 {};
    //use of deleted function
    //Widget w4(w1);
    
    //use of deleted function
    //w2 = w1;
    w1.show();
    w2.show();  
    w3.show();
    return 0;
}
