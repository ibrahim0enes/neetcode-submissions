class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Key: The number itself, Value: Its index in the array
        std::unordered_map<int, int> lookap;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Calculate the required value to reach the target
            int complement = target - nums[i];

            // 2. Check if the complement exists in our "Notebook" (Map)
            // .count() or .find() provides O(1) average search time
            if (lookap.count(complement)) {
                // Found it! Return the stored index and the current index
                return { lookap[complement], i };
            }

            // 3. If not found, store the current number and its index
            lookap.insert({nums[i], i});
        }

        // Return an empty vector if no solution is found
        return {};
    }
};