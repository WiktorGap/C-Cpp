#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { static_cast<int>(i), static_cast<int>(j) };
                }
            }
        }
        return {}; 
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = solution.twoSum(nums, target);
    if (!result.empty())
    {
        std::cout << "Your idx: " << result[0] << " , " << result[1] << std::endl;
    }
    else
    {
        std::cout << "No solution found!" << std::endl;
    }

    return 0;
}
