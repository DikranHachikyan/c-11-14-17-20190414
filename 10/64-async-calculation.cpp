#include <iostream>
#include <vector>
#include <future>
#include <numeric>
#include <random>

static const int NUM = 100000000;
//static const int NUM = 5;

long long getProduct( std::vector<int> &v, std::vector<int> &w){
    auto vSize = v.size();

    auto fut1 = std::async([&]{
        return std::inner_product(&v[0], &v[vSize/4], &w[0],0LL); 
    });

    auto fut2 = std::async([&]{
        return std::inner_product(&v[vSize/4], &v[vSize/2], &w[vSize/4],0LL);
    });
    
    auto fut3 = std::async([&]{
        return std::inner_product(&v[vSize/2], &v[vSize * 3/4], &w[vSize/2],0LL); 
    });

    auto fut4 = std::async([&]{
        return std::inner_product(&v[vSize * 3/4], &v[vSize], &w[vSize * 3/4],0LL);
    });

    return fut1.get() + fut2.get() + fut3.get() + fut4.get();
}

int main(){
      
    std::cout<<std::endl;
    std::random_device seed;

    //engine
    std::mt19937 engine { seed() };

    std::uniform_int_distribution<int> dist(0,100);

    std::vector<int> v,w;

    v.reserve(NUM);
    w.reserve(NUM);
    
    for( int i = 0; i < NUM ; ++i){
        auto n1 = dist(engine);
        auto n2 = dist(engine);
        v.push_back( n1);
        w.push_back( n2);
        if (i < 10 ){
            std::cout << n1 << " - " << n2 << std::endl;
        }
    }

    std::cout << "get product:" << getProduct(v,w) << std::endl;

    std::cout << std::endl;
    return 0;
}
