#include <exception>

int main()
{
    while (true)
    {
        try{
            int *tab = new int [1000];
            throw std::exception();
        }catch (const std::exception &e)
        {

        }
    }
    return 0;
}