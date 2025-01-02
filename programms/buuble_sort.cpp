#include <iostream>
#include <algorithm>
#include <array>

template<typename T, size_t N>

void bubble_sort(std::array<T,N>& arr)
{
    for(std::size_t i =0; i < N-1;i++)
    {
        for(std::size_t j = 0; j < N-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
    
    std::array<int, 5> arr = {5,4,3,2,1};
    bubble_sort(arr);
    
    for(auto i : arr )
    {
        std::cout<<i;
    }

}