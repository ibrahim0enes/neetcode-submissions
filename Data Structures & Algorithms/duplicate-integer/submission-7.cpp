class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
            std::unordered_map<int, bool> seen;
            for (int num : nums) {

            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen[num] = true;
        }

        return false;
    }
};