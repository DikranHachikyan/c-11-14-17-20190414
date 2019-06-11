#include <iostream>

class Number {
    private:
        int value1 {};
        int value2 {};
    public:
        constexpr Number(int v1, int v2): value1 {v1}, value2 {v2}{}
        constexpr int sum() const { return value1 + value2; }
};

int main(){
      
    std::cout<<std::endl;
    constexpr int value = 2;
    constexpr Number nm { 4, value };
    constexpr int sm = nm.sum();
    std::cout<<"sm="<<sm<<std::endl;
    
    std::cout << std::endl;
    return 0;
}
