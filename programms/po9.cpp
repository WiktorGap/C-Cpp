#include <iostream>
#include <vector>
#include <utility>
#include <map>
template<typename T>

std::pair<T,unsigned int>

findMostOccurences(const std::vector<T> &v)
{

    if(v.empty())
    {
        throw std::length_error("Conteiner is empty");

    }

    std::map<T, size_t> map;
    map[v[0]]=1;


    for(const auto &value: v)
    {
        map[value]+=1;
    }


    //result.second=0
    std::pair<int,unsigned int > result;
    result.second = 0;
    for(const auto &value : map)
    {
        if(value.second> result.second)
        {
            result.second = value.second;
        }
        return result;
    }


    //for (const std::pair<T,size_t> &value : map)
    for (const auto &value : map)
    {
        std::cout<<value.first<<" "<<value.second<<" \n";
    }

    return std::make_pair(1,1);
}


int main()
{
    std::vector<int> numbers={1,35,5,315,1,1,15,1,5,6,6,8,2,7,2,5,7,2,62,6,7,2,6};

    std::pair<int,unsigned int> result = findMostOccurences<int>(numbers);
    std::cout<<"Najwiecej wystepuje "<<result.first<<" \n";
    std::cout<<"Wystepuje"<<result.second<<"razy";

    return 0;
}