#include <iostream>
#include <cstdlib>

void show( int param ){
    std::cout<<"int param:"<<param<<std::endl;
}

void show( char *param ){
    std::cout<<"char param:"<<param<<std::endl;
}

int main(){
    //Error
    //show(NULL);

    show(nullptr);
    
    return 0;
}
