class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> seen;
        for (int num : nums) {
        if (seen.count(num)) return true; // Eğer eleman zaten varsa 'duplicate' bulduk!
        seen.insert(num);
    }
    return false;
    }
};