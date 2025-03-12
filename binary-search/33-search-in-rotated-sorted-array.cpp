#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        // Find index of minimum
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int search_idx = l + (r - l) / 2;
            if (nums[search_idx] < nums[r]) {
                r = search_idx;
            } else {
                l = search_idx + 1;
            }
        }

        int min_idx = r;
        int min_value = nums[r];
        if (target < min_value) return -1;

        int bottom = binarySearch(nums, 0, min_idx, target);
        return bottom >= 0 ? bottom : binarySearch(nums, min_idx, nums.size() - 1, target);
    }

    int binarySearch(const std::vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int search_idx = l + (r - l) / 2;
            if (nums[search_idx] == target) {
                return search_idx;
            } else if (nums[search_idx] > target) {
                r = search_idx;
            } else {
                l = search_idx + 1;
            }
        }

        return nums[r] == target ? r : -1;
    }
};
