#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Anagram
{
public:
    bool check_if_anagram(const std::string& first_str, const std::string& second_str)
    {
        if(first_str.size() != second_str.size())
        {
            return false;
        }
        for(char c : first_str)
        {
            char_map_count[tolower(c)]++;
        }
        for(char c : second_str)
        {
            char char_lower = tolower(c);
            if (char_map_count[char_lower]==0) return false;
            char_map_count[char_lower]--;
        }
        std::cout<<"To są anagramy";
        return true;

    }

private:
    std::string first_str;
    std::string second_str;
    std::unordered_map<char, int> char_map_count; 
};

int main()
{

    Anagram anagram;
    anagram.check_if_anagram("barok","korba");

    return 0;
}
