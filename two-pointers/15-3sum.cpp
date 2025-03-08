// Solution: incredibly painful. Whoever decided that indexes should start at 0 should die in a hellfire.
// Iterate through the array, using the diff between the curr element and 0 as the target.
// Do sorted 2 pointers on the remainder of the array, skipping same values as they will result in duplicate
// triplets.
// Requires O(n^2) time complexity for the 2 pointers solution per element, and space complexity is dependent
// on language implementation ( O(n log n) for C++).

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        int i = 0;
        while (i < nums.size() - 2) {
            if (nums[i] > 0) return result;
            int target = 0 - nums[i];

            // Set boundaries
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    result.emplace_back(std::vector{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++l]);
                } else if (nums[l] + nums[r] > target) {
                    --r;
                } else {
                    ++l;
                }
            }

            while (i < r && nums[i] == nums[++i]);
        }
        return result;
    }
};
