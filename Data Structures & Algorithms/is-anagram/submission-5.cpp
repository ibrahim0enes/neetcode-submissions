class Solution {
public:
    bool isAnagram(string s, string t) { 

        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> count;

        for (int i = 0; i < s.size(); i++) 
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        for (auto const& [key, val] : count) 
        { 
            if (val != 0) 
            {
                return false;
            }
        }
        return true;
    }
};
