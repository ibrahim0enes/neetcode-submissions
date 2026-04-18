class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {       
    unordered_map <int , int> book;
    for(int i = 0; i < nums.size(); i++){     
    
     if(book.count(nums[i])){
        
        return {book[nums[i]], i};  
     }
     book[target - nums[i]] = i;

    }    
    return{};
    }
};
