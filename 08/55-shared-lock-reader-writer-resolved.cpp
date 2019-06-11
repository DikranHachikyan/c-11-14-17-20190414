#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <shared_mutex>
#include <map>

std::map<std::string, int> contacts { {"Anna",1111}, {"John",2222},{"Maria",3333}};

std::shared_timed_mutex conactsMtx;

void addContact( const std::string &name , int phone){
    std::lock_guard<std::shared_timed_mutex> writeLock { conactsMtx};

    std::cout << "\nStart update " << name;
    
    std::this_thread::sleep_for( std::chrono::milliseconds(500));
    
    contacts[name] = phone;
    
    std::cout << "... end of update " << name << std::endl;

}

void printContact( const std::string &name){
    std::shared_lock<std::shared_timed_mutex> readerLock {conactsMtx};
    auto rec = contacts.find(name);
    if( rec != contacts.end() ){
        std::cout << rec->first << ":" << rec->second << std::endl;
    }
    else{
        std::cout << name << " not found" << std::endl;
    }
}


int main(){
      
    std::cout<<std::endl;
    std::thread r1 {[]{ printContact("Anna");}};
    std::thread r2 {[]{ printContact("John");}};
    std::thread r3 {[]{ printContact("Scott");}};
    std::thread w1 {[]{ addContact("Scott",7777);}};
    std::thread r4 {[]{ printContact("John");}};
    std::thread r5 {[]{ printContact("Maria");}};
    std::thread w2 {[]{ addContact("George",8888);}};
    std::thread r6 {[]{ printContact("Maria");}};
    std::thread r7 {[]{ printContact("George");}};

    r1.join();
    r2.join();
    r3.join();
    r4.join();
    r5.join();
    r6.join();
    r7.join();
    w1.join();
    w2.join();
    std::cout << std::endl;
    return 0;
}
