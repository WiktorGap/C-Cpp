#include <thread>
#include <iostream>
#include <string>
#include <unistd.h>

std::string sharedString;
volatile bool flag = false;

void threadFunc()
{
    std::cout<<"wątek oczekuje na zmainę flagi\n";
    while(!flag);
    sleep(3);
    std::cout<<"wątek zaczyna działanie\n";
    std::cout<<sharedString;
    sharedString = "kot ma ale";
    flag = false;
    sleep(10);
}

int main()
{
    std::thread t(threadFunc);
    sleep(3);
    sharedString = " ale ma kota";
    std::cout<<"main zmienia flagę\n";
    flag = true;
    while(flag);
    std::cout<<sharedString;
    t.join();
    return 0;


}