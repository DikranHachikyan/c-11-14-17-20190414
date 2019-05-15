#include <iostream>
#include <cstdlib>


int main(){
    double x = 1.23, y = 2.56, z = 3.78;
    
    //type narrowing
    int sum = x + y + z;
    int sum1( x + y + z );
    //compile time error
    //int sum2 {x + y + z};

    std::cout<<"sum = "<<sum<<std::endl;
    std::cout<<"sum1 = "<<sum1<<std::endl;
    //std::cout<<"sum2 = "<<sum2<<std::endl;

    return 0;
}
