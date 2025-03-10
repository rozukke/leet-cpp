// Solution: pretty boring.

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int low = 0;
        int high = nums.size() - 1;
        while (low != high) {
            int search_idx = low + (low - high) / 2;
            if (nums[search_idx] == target) return search_idx;

            if (nums[search_idx] > target) {
                high = search_idx - 1;
            } else {
                low = search_idx + 1;
            }
        }
        return -1;
    }
};
