class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
       int count = 0;
       for(int x :nums){
          count = 0;
         for(int v :nums){
          
          if(x == v){
            count++;
          }
        }
       }

       if(count > 1) {
        return true;
       }
       else{

        return false;
       }
    }
};