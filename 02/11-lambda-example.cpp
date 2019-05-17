#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> values {1,2,3,4,5,6,7,8,9,10};
    int k = 4;

    auto gt = [k](int v)->bool{ return v > k; };

    auto gt_count = std::count_if(std::cbegin(values), 
                                  std::cend(values), 
                                  gt);
    std::cout<<gt_count<<" elements greater than "<<k<<std::endl;

    auto le = [k](int v)->bool{return v <= k;};

    auto iter = std::remove_if(std::begin(values),std::end(values),le);
    values.erase(iter, std::end(values));
    
    std::cout<<"after remove:"<<std::endl;
    for( auto v : values){
        std::cout<<v<<"|";
    }
    std::cout<<std::endl;
    return 0;
}
