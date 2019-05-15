#include <iostream>
#include <cstdlib>
#include <vector>

int main(){
    //std::vector<int> values(3);
    //std::vector<int> values(3, 4);
    std::vector<int> values {1,2,3,4,5,6};

    for(int v: values){
        std::cout<<"v="<<v<<std::endl;
    }

    return 0;
}
