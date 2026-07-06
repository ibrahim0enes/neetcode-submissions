class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
       if (nums.empty()) return false;
       int  i = 0;
       int  j;
       int  n = nums.size();
        while (i < n)
        {   
            j = i + 1;
            while (j < n)
            {
                if (nums[i] == nums[j])
                {
                   return (true);
                }
                j++;
            }
            i++;
        }
        return (false);
    }
};