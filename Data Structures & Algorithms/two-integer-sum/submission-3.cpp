class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> restToIndex{};

        for(int i = 0; i < nums.size(); i++)
        {
            if(restToIndex.count(nums[i]))
            {
                return {restToIndex[nums[i]], i};
            }
            restToIndex[target - nums[i]] = i;
        }

        return {};
    }
};
