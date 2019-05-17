#include <iostream>
#include <typeinfo>
#include <string>

int global_value = 20;

// void foo(){
//     static int v = 2;
//     std::cout<<"v="<<++v<<std::endl; 
// }
int main(){
    static int static_z = 1;
    const int const_port = 80;

    auto show = [msg="Message Text"](){
        static_z = 11;
        global_value = 100;
        std::cout<<msg<<"\n"
                 <<"global value:"<<global_value<<"\n"
                 <<"static z:"<<static_z<<"\n"
                 <<"const port:"<<const_port
                 <<std::endl;
    };

    show();
    // foo();
    // foo();
    // foo();
    return 0;
}
