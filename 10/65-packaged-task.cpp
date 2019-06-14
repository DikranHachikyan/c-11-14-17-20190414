#include <iostream>
#include <future>
#include <deque>
#include <utility>

class Sum{
    public:
        int operator()(int beg, int end){
            int sum {0};
            std::cout << "start calculation" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            for( int i = beg ; i < end ; ++i){
                sum += i;
            }
            return sum;
        }
};



int main(){
      
    std::cout<<std::endl;
    Sum s1, s2, s3, s4;

    //wrap
    std::packaged_task<int(int,int)> ts1 {s1};
    std::packaged_task<int(int,int)> ts2 {s2};
    std::packaged_task<int(int,int)> ts3 {s3};
    std::packaged_task<int(int,int)> ts4 {s4};

    //futures
    //std::future<int> res1 = ts1.get_future();
    auto res1 = ts1.get_future();
    auto res2 = ts2.get_future();
    auto res3 = ts3.get_future();
    auto res4 = ts4.get_future();

    //push tasks
    std::deque<std::packaged_task<int(int,int)>> tasks;

    tasks.push_back( std::move(ts1));
    tasks.push_back( std::move(ts2));
    tasks.push_back( std::move(ts3));
    tasks.push_back( std::move(ts4));

    int start {1};
    int incr  {2500};
    int end = start + incr;
    
    std::cout << "before loop" << std::endl;
    //calc
    while( not tasks.empty() ){
        std::packaged_task<int(int,int)> cts = std::move(tasks.front());
        tasks.pop_front();
        std::thread sumTh {std::move( cts), start, end};
        start = end;
        end += incr;
        sumTh.detach();
    }

    std::cout << "before get:" << std::endl;
    //results
    auto r = res1.get() + res2.get() + res3.get() + res4.get();
    std::cout << "sum of 1..10 000:" << r << std::endl;

    std::cout << std::endl;
    return 0;
}
