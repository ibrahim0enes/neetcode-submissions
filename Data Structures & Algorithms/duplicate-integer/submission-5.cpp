class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
       int count = 0;
       
       for(int x = 0;x<nums.size();x++){
          count = 0;
         for(int v = x + 1;v<nums.size();v++){
          
          if(nums[x] == nums[v]){
            return true;

          }
         
        }
       }
        return false;
       
    }
};