class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
       unordered_map <string , vector<string>> prevmap;
       for(string &s : strs){
        string key = s;
        sort(key.begin(),key.end());
        prevmap[key].push_back(s);
       }
       
       vector<vector<string>> result;
       for(auto &entry : prevmap ){
           result.push_back(entry.second);
     
       }
       return result;



    }
};
