#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map{};
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (map.find(num) != map.end()) {
                return {map[num], i};
            }
            map[target - num] = i;
        }
        // unreachable
        return {0, 0};
    }
};
