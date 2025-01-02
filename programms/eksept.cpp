#include <stdexcept>
#include <iostream>
double mydiv(int a , u_int b)
{
    if(b==0)
    {
        throw std::invalid_argument("BOOM!");
    }
    return a/b;
}

int main()
{
    try
    {
        mydiv(5,0);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<'\n';
    }
    std::cout<<"Kontynuacja programu";

    return 0;
}